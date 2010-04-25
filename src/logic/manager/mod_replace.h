#ifndef PROTOGEN_MANAGER_MOD_REPLACE_H__
#define PROTOGEN_MANAGER_MOD_REPLACE_H__
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
#include "manager/proto.h"
#include "logic/msgtype.h"
#include "logic/cluster_logic.h"
#include <msgpack.hpp>
#include <string>
#include <stdint.h>

namespace kumo {
namespace manager {



class framework;
class mod_replace_t  {
public:
	struct ReplaceElection : rpc::message<12, 0, rpc::node> {
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
		typedef rpc::retry<ReplaceElection> retry;
		ReplaceElection(
				const msgtype::HSSeed& hsseed_,
				const Clock& adjust_clock_) :
				hsseed(hsseed_), adjust_clock(adjust_clock_) { }
		ReplaceElection() { }

		// sender   of ReplaceElection is responsible for replacing: true
		// receiver of ReplaceElection is responsible for replacing: nil
	};
	void rpc_ReplaceElection(rpc::request<ReplaceElection>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct ReplaceDeleteEnd : rpc::message<11, 0, rpc::node> {
		ClockTime replace_time;
		Clock adjust_clock;
		void msgpack_unpack(const msgpack::type::tuple<
				ClockTime, Clock >& args)
		{
			this->replace_time = args.get<0>();
			this->adjust_clock = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(replace_time);
			pk.pack(adjust_clock);
		}
		typedef rpc::retry<ReplaceDeleteEnd> retry;
		ReplaceDeleteEnd(
				const ClockTime& replace_time_,
				const Clock& adjust_clock_) :
				replace_time(replace_time_), adjust_clock(adjust_clock_) { }
		ReplaceDeleteEnd() { }

		// acknowledge: true
	};
	void rpc_ReplaceDeleteEnd(rpc::request<ReplaceDeleteEnd>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct ReplaceCopyEnd : rpc::message<10, 0, rpc::node> {
		ClockTime replace_time;
		Clock adjust_clock;
		void msgpack_unpack(const msgpack::type::tuple<
				ClockTime, Clock >& args)
		{
			this->replace_time = args.get<0>();
			this->adjust_clock = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(replace_time);
			pk.pack(adjust_clock);
		}
		typedef rpc::retry<ReplaceCopyEnd> retry;
		ReplaceCopyEnd(
				const ClockTime& replace_time_,
				const Clock& adjust_clock_) :
				replace_time(replace_time_), adjust_clock(adjust_clock_) { }
		ReplaceCopyEnd() { }

		// acknowledge: true
	};
	void rpc_ReplaceCopyEnd(rpc::request<ReplaceCopyEnd>&, rpc::auto_zone z,
			rpc::weak_responder);

public:
	mod_replace_t();
	~mod_replace_t();

public:
	void attach_new_servers(REQUIRE_HSLK);
	void detach_fault_servers(REQUIRE_HSLK);

	void start_replace(REQUIRE_HSLK, bool full = false);
	void add_server(const address& addr, shared_node& s);
	void remove_server(const address& addr);

private:
	void replace_election();
	void delayed_replace_election();
	void cas_checked_replace_election(int cas);
	int m_delayed_replace_cas;

	RPC_REPLY_DECL(ReplaceElection, from, res, err, z);
	RPC_REPLY_DECL(ReplaceCopyStart, from, res, err, z);
	RPC_REPLY_DECL(ReplaceDeleteStart, from, res, err, z);

	void finish_replace_copy(REQUIRE_RELK);
	void finish_replace(REQUIRE_RELK);

private:
	class progress {
	public:
		progress();
		~progress();
	public:
		typedef std::vector<rpc::address> nodes_t;
		ClockTime clocktime() const;
	public:
		void reset(ClockTime ct, const nodes_t& nodes);
		bool pop(ClockTime ct, const rpc::address& node);
		nodes_t invalidate();
	private:
		nodes_t m_remainder;
		nodes_t m_target_nodes;
		ClockTime m_clocktime;
	};

	mp::pthread_mutex m_replace_mutex;
	progress m_copying;
	progress m_deleting;
};


}  // namespace manager
}  // namespace kumo

#endif
