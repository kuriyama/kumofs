#ifndef PROTOGEN_MANAGER_MOD_CONTROL_H__
#define PROTOGEN_MANAGER_MOD_CONTROL_H__
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




class mod_control_t  {
public:
	struct GetNodesInfo : rpc::message<99, 0, rpc::basic_session> {
		
		void msgpack_unpack(const msgpack::type::tuple<
				 >& args)
		{
			
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(0);
			
		}
		typedef rpc::retry<GetNodesInfo> retry;
		GetNodesInfo() { }

		
	};
	void rpc_GetNodesInfo(rpc::request<GetNodesInfo>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct SetAutoReplace : rpc::message<103, 0, rpc::basic_session> {
		bool enable;
		void msgpack_unpack(const msgpack::type::tuple<
				bool >& args)
		{
			this->enable = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(enable);
		}
		typedef rpc::retry<SetAutoReplace> retry;
		SetAutoReplace(
				const bool& enable_) :
				enable(enable_) { }
		SetAutoReplace() { }

		
	};
	void rpc_SetAutoReplace(rpc::request<SetAutoReplace>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct DetachFaultServers : rpc::message<101, 0, rpc::basic_session> {
		bool replace;
		void msgpack_unpack(const msgpack::type::tuple<
				bool >& args)
		{
			this->replace = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(replace);
		}
		typedef rpc::retry<DetachFaultServers> retry;
		DetachFaultServers(
				const bool& replace_) :
				replace(replace_) { }
		DetachFaultServers() { }

		
	};
	void rpc_DetachFaultServers(rpc::request<DetachFaultServers>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct AttachNewServers : rpc::message<100, 0, rpc::basic_session> {
		bool replace;
		void msgpack_unpack(const msgpack::type::tuple<
				bool >& args)
		{
			this->replace = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(replace);
		}
		typedef rpc::retry<AttachNewServers> retry;
		AttachNewServers(
				const bool& replace_) :
				replace(replace_) { }
		AttachNewServers() { }

		
	};
	void rpc_AttachNewServers(rpc::request<AttachNewServers>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct CreateBackup : rpc::message<102, 0, rpc::basic_session> {
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

		
	};
	void rpc_CreateBackup(rpc::request<CreateBackup>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct StartReplace : rpc::message<104, 0, rpc::basic_session> {
		bool full;
		void msgpack_unpack(msgpack::object o)
		{
			if(o.type != msgpack::type::ARRAY) { throw msgpack::type_error(); }
			if(o.via.array.size > 0) { o.via.array.ptr[0].convert(&this->full); }
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(full);
		}
		typedef rpc::retry<StartReplace> retry;
		StartReplace(
				bool full_ = false) :
				full(full_) { }

		
	};
	void rpc_StartReplace(rpc::request<StartReplace>&, rpc::auto_zone z,
			rpc::weak_responder);

public:
	mod_control_t();
	~mod_control_t();

public:
	void listen_control(int lsock);

private:
	struct Status : msgpack::define< msgpack::type::tuple<
				msgtype::HSSeed, std::vector<address> > > {
		Status() { }
		msgtype::HSSeed& hsseed() { return get<0>(); }
		std::vector<address>& newcomers() { return get<1>(); }
	};

	RPC_REPLY_DECL(CreateBackup, from, res, err, z);
};

}  // namespace manager
}  // namespace kumo

#endif
