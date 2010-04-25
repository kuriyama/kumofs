#ifndef PROTOGEN_SERVER_PROTO_H__
#define PROTOGEN_SERVER_PROTO_H__
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


namespace proto {
	enum mod_control_t {
		SetConfig = 98,
		CreateBackup = 96,
		GetStatus = 97,
	};
	enum mod_store_t {
		Get = 34,
		ReplicateDelete = 33,
		Set = 35,
		ReplicateSet = 32,
		GetIfModified = 37,
		Delete = 36,
	};
	enum mod_replace_t {
		ReplaceCopyStart = 8,
		ReplaceDeleteStart = 9,
	};
	enum mod_network_t {
		HashSpaceSync = 2,
		KeepAlive = 0,
	};
	enum mod_replace_stream_t {
		ReplaceOffer = 16,
	};
}







}  // namespace server
}  // namespace kumo

#endif
