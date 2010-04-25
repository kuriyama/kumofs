#ifndef PROTOGEN_SERVER_MOD_CONTROL_H__
#define PROTOGEN_SERVER_MOD_CONTROL_H__
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








enum status_type {
	STAT_PID			= 0,
	STAT_UPTIME			= 1,
	STAT_TIME			= 2,
	STAT_VERSION		= 3,
	STAT_CMD_GET		= 4,
	STAT_CMD_SET		= 5,
	STAT_CMD_DELETE		= 6,
	STAT_DB_ITEMS		= 7,
	STAT_CLOCKTIME		= 8,
	STAT_RHS			= 9,
	STAT_WHS			= 10,
};

enum config_type {
	CONF_TCP_NODELAY    = 0,  // FIXME experimental
};
class mod_control_t  {
public:
	struct SetConfig : rpc::message<98, 0, rpc::basic_session> {
		uint32_t command;
		msgpack::object arg;
		void msgpack_unpack(const msgpack::type::tuple<
				uint32_t, msgpack::object >& args)
		{
			this->command = args.get<0>();
			this->arg = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(command);
			pk.pack(arg);
		}
		typedef rpc::retry<SetConfig> retry;
		SetConfig(
				const uint32_t& command_,
				const msgpack::object& arg_) :
				command(command_), arg(arg_) { }
		SetConfig() { }

		
	};
	void rpc_SetConfig(rpc::request<SetConfig>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct CreateBackup : rpc::message<96, 0, rpc::basic_session> {
		std::string suffix;
		void msgpack_unpack(const msgpack::type::tuple<
				std::string >& args)
		{
			this->suffix = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(suffix);
		}
		typedef rpc::retry<CreateBackup> retry;
		CreateBackup(
				const std::string& suffix_) :
				suffix(suffix_) { }
		CreateBackup() { }

		// success: true
	};
	void rpc_CreateBackup(rpc::request<CreateBackup>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct GetStatus : rpc::message<97, 0, rpc::basic_session> {
		uint32_t command;
		void msgpack_unpack(const msgpack::type::tuple<
				uint32_t >& args)
		{
			this->command = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(command);
		}
		typedef rpc::retry<GetStatus> retry;
		GetStatus(
				const uint32_t& command_) :
				command(command_) { }
		GetStatus() { }

		
	};
	void rpc_GetStatus(rpc::request<GetStatus>&, rpc::auto_zone z,
			rpc::weak_responder);


};

}  // namespace server
}  // namespace kumo

#endif
