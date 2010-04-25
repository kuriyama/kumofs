#ifndef PROTOGEN_SERVER_MOD_REPLACE_STREAM_H__
#define PROTOGEN_SERVER_MOD_REPLACE_STREAM_H__
/* This is generated file. */
//
// kumofs
//
// Copyright (C) 2009 FURUHASHI Sadayuki
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//
#include "server/proto.h"
#include "logic/msgtype.h"
#include "logic/cluster_logic.h"
#include <msgpack.hpp>
#include <string>
#include <stdint.h>

namespace kumo {
namespace server {







class mod_replace_stream_t  {
public:
	struct ReplaceOffer : rpc::message<16, 0, rpc::node> {
		address addr;
		void msgpack_unpack(const msgpack::type::tuple<
				address >& args)
		{
			this->addr = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(addr);
		}
		typedef rpc::retry<ReplaceOffer> retry;
		ReplaceOffer(
				const address& addr_) :
				addr(addr_) { }
		ReplaceOffer() { }

		// no response
	};
	void rpc_ReplaceOffer(rpc::request<ReplaceOffer>&, rpc::auto_zone z,
			rpc::weak_responder);

public:
	mod_replace_stream_t(address stream_addr);
	~mod_replace_stream_t();

private:
	int m_stream_lsock;
	address m_stream_addr;

public:
	const address& stream_addr() const
	{
		return m_stream_addr;
	}

	void init_stream(int lsock);
	void stop_stream();

private:
	class stream_accumulator;
	typedef mp::shared_ptr<stream_accumulator> shared_stream_accumulator;
	typedef std::vector<shared_stream_accumulator> accum_set_t;

public:
	class offer_storage {
	public:
		offer_storage(const std::string& basename, ClockTime replace_time);
		~offer_storage();
	public:
		void add(const address& addr,
				const char* key, size_t keylen,
				const char* val, size_t vallen);
		void flush();
		void commit(accum_set_t* dst);
	private:
		accum_set_t m_set;
		const std::string& m_basename;
		ClockTime m_replace_time;
	private:
		offer_storage();
		offer_storage(const offer_storage&);
	};

	void send_offer(offer_storage& offer, ClockTime replace_time);

private:
	mp::pthread_mutex m_accum_set_mutex;
	accum_set_t m_accum_set;

	struct accum_set_comp;
	static accum_set_t::iterator accum_set_find(
			accum_set_t& map, const address& addr);

	RPC_REPLY_DECL(ReplaceOffer, from, res, err, z,
			address addr);

	void stream_accepted(int fd, int err);
	void stream_connected(int fd, int err);

	std::auto_ptr<mp::wavy::core> m_stream_core;
	class stream_handler;
	friend class stream_handler;
};


}  // namespace server
}  // namespace kumo

#endif
