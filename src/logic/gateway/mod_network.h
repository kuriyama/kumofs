#ifndef PROTOGEN_GATEWAY_MOD_NETWORK_H__
#define PROTOGEN_GATEWAY_MOD_NETWORK_H__
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
#include "gateway/proto.h"
#include "logic/msgtype.h"
#include "logic/client_logic.h"
#include <msgpack.hpp>
#include <string>
#include <stdint.h>

namespace kumo {
namespace gateway {


class mod_network_t  {
public:
	struct HashSpacePush : rpc::message<3, 0, rpc::basic_session> {
		msgtype::HSSeed wseed;
		msgtype::HSSeed rseed;
		void msgpack_unpack(const msgpack::type::tuple<
				msgtype::HSSeed, msgtype::HSSeed >& args)
		{
			this->wseed = args.get<0>();
			this->rseed = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(wseed);
			pk.pack(rseed);
		}
		typedef rpc::retry<HashSpacePush> retry;
		HashSpacePush(
				const msgtype::HSSeed& wseed_,
				const msgtype::HSSeed& rseed_) :
				wseed(wseed_), rseed(rseed_) { }
		HashSpacePush() { }

		// acknowledge: true
	};
	void rpc_HashSpacePush(rpc::request<HashSpacePush>&, rpc::auto_zone z,
			rpc::weak_responder);

public:
	void keep_alive();

	void renew_hash_space();
	void renew_hash_space_for(const address& addr);
	RPC_REPLY_DECL(HashSpaceRequest, from, res, err, z);
};

}  // namespace gateway
}  // namespace kumo

#endif
