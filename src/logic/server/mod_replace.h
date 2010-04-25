#ifndef PROTOGEN_SERVER_MOD_REPLACE_H__
#define PROTOGEN_SERVER_MOD_REPLACE_H__
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






class mod_replace_t  {
public:
	struct ReplaceCopyStart : rpc::message<8, 0, rpc::node> {
		msgtype::HSSeed hsseed;
		Clock adjust_clock;
		bool full;
		void msgpack_unpack(msgpack::object o)
		{
			const msgpack::type::tuple<msgtype::HSSeed, Clock, bool >& args(o.convert());
			this->hsseed = args.get<0>();
			this->adjust_clock = args.get<1>();
			if(o.via.array.size > 2) { o.via.array.ptr[2].convert(&this->full); }
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(3);
			pk.pack(hsseed);
			pk.pack(adjust_clock);
			pk.pack(full);
		}
		typedef rpc::retry<ReplaceCopyStart> retry;
		ReplaceCopyStart(
				const msgtype::HSSeed& hsseed_,
				const Clock& adjust_clock_,
				bool full_ = false) :
				hsseed(hsseed_), adjust_clock(adjust_clock_), full(full_) { }
		ReplaceCopyStart() :
				full(false) { }

		// accepted: true
	};
	void rpc_ReplaceCopyStart(rpc::request<ReplaceCopyStart>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct ReplaceDeleteStart : rpc::message<9, 0, rpc::node> {
		msgtype::HSSeed hsseed;
		Clock adjust_clock;
		void msgpack_unpack(const msgpack::type::tuple<
				msgtype::HSSeed, Clock >& args)
		{
			this->hsseed = args.get<0>();
			this->adjust_clock = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(hsseed);
			pk.pack(adjust_clock);
		}
		typedef rpc::retry<ReplaceDeleteStart> retry;
		ReplaceDeleteStart(
				const msgtype::HSSeed& hsseed_,
				const Clock& adjust_clock_) :
				hsseed(hsseed_), adjust_clock(adjust_clock_) { }
		ReplaceDeleteStart() { }

		// accepted: true
	};
	void rpc_ReplaceDeleteStart(rpc::request<ReplaceDeleteStart>&, rpc::auto_zone z,
			rpc::weak_responder);

private:
	static bool test_replicator_assign(const HashSpace& hs, uint64_t h, const address& target);

	typedef std::vector<address> addrvec_t;
	typedef addrvec_t::iterator addrvec_iterator;

	struct for_each_replace_copy;
	struct for_each_full_replace_copy;
	void replace_copy(const address& manager_addr, HashSpace& hs, shared_zone life);
	void full_replace_copy(const address& manager_addr, HashSpace& hs, shared_zone life);

	void finish_replace_copy(ClockTime clocktime, REQUIRE_STLK);
	RPC_REPLY_DECL(ReplaceCopyEnd, from, res, err, z);

	void replace_delete(shared_node& manager, HashSpace& hs, shared_zone life);
	struct for_each_replace_delete;
	RPC_REPLY_DECL(ReplaceDeleteEnd, from, res, err, z);

private:
	class replace_state {
	public:
		replace_state();
		~replace_state();
	public:
		void reset(const address& mgr, ClockTime ct);
		void pushed(ClockTime ct);
		void push_returned(ClockTime ct);
		const address& mgr_addr() const;
		bool is_finished(ClockTime ct) const;
		void invalidate();
	private:
		int m_push_waiting;
		ClockTime m_clocktime;
		address m_mgr;
	};

	mp::pthread_mutex m_state_mutex;
	replace_state m_state;

public:
	void replace_offer_push(ClockTime replace_time, REQUIRE_STLK);
	void replace_offer_pop(ClockTime replace_time, REQUIRE_STLK);
	mp::pthread_mutex& state_mutex() { return m_state_mutex; }
};



}  // namespace server
}  // namespace kumo

#endif
