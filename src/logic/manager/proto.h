#ifndef PROTOGEN_MANAGER_PROTO_H__
#define PROTOGEN_MANAGER_PROTO_H__
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


namespace proto {
	enum mod_control_t {
		GetNodesInfo = 99,
		SetAutoReplace = 103,
		DetachFaultServers = 101,
		AttachNewServers = 100,
		CreateBackup = 102,
		StartReplace = 104,
	};
	enum mod_replace_t {
		ReplaceElection = 12,
		ReplaceDeleteEnd = 11,
		ReplaceCopyEnd = 10,
	};
	enum mod_network_t {
		RHashSpaceRequest = 5,
		HashSpaceRequest = 1,
		WHashSpaceRequest = 4,
		HashSpaceSync = 2,
		KeepAlive = 0,
	};
}



}  // namespace manager
}  // namespace kumo

#endif
