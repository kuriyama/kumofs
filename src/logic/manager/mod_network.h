#ifndef PROTOGEN_MANAGER_MOD_NETWORK_H__
#define PROTOGEN_MANAGER_MOD_NETWORK_H__
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


class mod_network_t  {
public:
	struct RHashSpaceRequest : rpc::message<5, 0, rpc::basic_session> {
		
		void msgpack_unpack(const msgpack::type::tuple<
				 >& args)
		{
			
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(0);
			
		}
		typedef rpc::retry<RHashSpaceRequest> retry;
		RHashSpaceRequest() { }

		// success: hash_space:tuple<array<raw_ref>,uint64_t>
	};
	void rpc_RHashSpaceRequest(rpc::request<RHashSpaceRequest>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct HashSpaceRequest : rpc::message<1, 0, rpc::basic_session> {
		
		void msgpack_unpack(const msgpack::type::tuple<
				 >& args)
		{
			
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(0);
			
		}
		typedef rpc::retry<HashSpaceRequest> retry;
		HashSpaceRequest() { }

		// success: gateway::mod_network_t::HashSpacePush
	};
	void rpc_HashSpaceRequest(rpc::request<HashSpaceRequest>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct WHashSpaceRequest : rpc::message<4, 0, rpc::basic_session> {
		
		void msgpack_unpack(const msgpack::type::tuple<
				 >& args)
		{
			
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(0);
			
		}
		typedef rpc::retry<WHashSpaceRequest> retry;
		WHashSpaceRequest() { }

		// success: hash_space:tuple<array<raw_ref>,uint64_t>
	};
	void rpc_WHashSpaceRequest(rpc::request<WHashSpaceRequest>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct HashSpaceSync : rpc::message<2, 0, rpc::node> {
		msgtype::HSSeed wseed;
		msgtype::HSSeed rseed;
		Clock adjust_clock;
		void msgpack_unpack(const msgpack::type::tuple<
				msgtype::HSSeed, msgtype::HSSeed, Clock >& args)
		{
			this->wseed = args.get<0>();
			this->rseed = args.get<1>();
			this->adjust_clock = args.get<2>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(3);
			pk.pack(wseed);
			pk.pack(rseed);
			pk.pack(adjust_clock);
		}
		typedef rpc::retry<HashSpaceSync> retry;
		HashSpaceSync(
				const msgtype::HSSeed& wseed_,
				const msgtype::HSSeed& rseed_,
				const Clock& adjust_clock_) :
				wseed(wseed_), rseed(rseed_), adjust_clock(adjust_clock_) { }
		HashSpaceSync() { }

		// success: true
		// obsolete: nil
	};
	void rpc_HashSpaceSync(rpc::request<HashSpaceSync>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct KeepAlive : rpc::message<0, 0, rpc::node> {
		Clock adjust_clock;
		void msgpack_unpack(const msgpack::type::tuple<
				Clock >& args)
		{
			this->adjust_clock = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(adjust_clock);
		}
		typedef rpc::retry<KeepAlive> retry;
		KeepAlive(
				const Clock& adjust_clock_) :
				adjust_clock(adjust_clock_) { }
		KeepAlive() { }

		// ok: UNDEFINED
	};
	void rpc_KeepAlive(rpc::request<KeepAlive>&, rpc::auto_zone z,
			rpc::weak_responder);

public:
	void keep_alive();

	void sync_hash_space_servers(REQUIRE_HSLK);
	void sync_hash_space_partner(REQUIRE_HSLK);
	void push_hash_space_clients(REQUIRE_HSLK);

private:
	RPC_REPLY_DECL(KeepAlive, from, res, err, z);
	RPC_REPLY_DECL(HashSpaceSync, from, res, err, z);
	RPC_REPLY_DECL(HashSpacePush, from, res, err, z);
};



}  // namespace manager
}  // namespace kumo

#endif
