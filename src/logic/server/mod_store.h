#ifndef PROTOGEN_SERVER_MOD_STORE_H__
#define PROTOGEN_SERVER_MOD_STORE_H__
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



struct store_flags;
typedef msgtype::flags<store_flags, 0>    store_flags_none;
typedef msgtype::flags<store_flags, 0x01> store_flags_async;
struct store_flags : public msgtype::flags_base {
	bool is_async() { return is_set<store_flags_async>(); }
};

struct replicate_flags;
typedef msgtype::flags<replicate_flags, 0>    replicate_flags_none;
typedef msgtype::flags<replicate_flags, 0x01> replicate_flags_by_rhs;
struct replicate_flags : msgtype::flags_base {
	bool is_rhs() const { return is_set<replicate_flags_by_rhs>(); }
};

class mod_store_t  {
public:
	struct Get : rpc::message<34, 0, rpc::basic_session> {
		msgtype::DBKey dbkey;
		void msgpack_unpack(const msgpack::type::tuple<
				msgtype::DBKey >& args)
		{
			this->dbkey = args.get<0>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(1);
			pk.pack(dbkey);
		}
		typedef rpc::retry<Get> retry;
		Get(
				const msgtype::DBKey& dbkey_) :
				dbkey(dbkey_) { }
		Get() { }

		// success: value:DBValue
		// not found: nil
	};
	void rpc_Get(rpc::request<Get>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct ReplicateDelete : rpc::message<33, 0, rpc::basic_session> {
		Clock adjust_clock;
		replicate_flags flags;
		ClockTime delete_clocktime;
		msgtype::DBKey dbkey;
		void msgpack_unpack(const msgpack::type::tuple<
				Clock, replicate_flags, ClockTime, msgtype::DBKey >& args)
		{
			this->adjust_clock = args.get<0>();
			this->flags = args.get<1>();
			this->delete_clocktime = args.get<2>();
			this->dbkey = args.get<3>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(4);
			pk.pack(adjust_clock);
			pk.pack(flags);
			pk.pack(delete_clocktime);
			pk.pack(dbkey);
		}
		typedef rpc::retry<ReplicateDelete> retry;
		ReplicateDelete(
				const Clock& adjust_clock_,
				const replicate_flags& flags_,
				const ClockTime& delete_clocktime_,
				const msgtype::DBKey& dbkey_) :
				adjust_clock(adjust_clock_), flags(flags_), delete_clocktime(delete_clocktime_), dbkey(dbkey_) { }
		ReplicateDelete() { }

		// success: true
		// ignored: false
	};
	void rpc_ReplicateDelete(rpc::request<ReplicateDelete>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct Set : rpc::message<35, 0, rpc::basic_session> {
		store_flags flags;
		msgtype::DBKey dbkey;
		msgtype::DBValue dbval;
		void msgpack_unpack(const msgpack::type::tuple<
				store_flags, msgtype::DBKey, msgtype::DBValue >& args)
		{
			this->flags = args.get<0>();
			this->dbkey = args.get<1>();
			this->dbval = args.get<2>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(3);
			pk.pack(flags);
			pk.pack(dbkey);
			pk.pack(dbval);
		}
		typedef rpc::retry<Set> retry;
		Set(
				const store_flags& flags_,
				const msgtype::DBKey& dbkey_,
				const msgtype::DBValue& dbval_) :
				flags(flags_), dbkey(dbkey_), dbval(dbval_) { }
		Set() { }

		// success: clocktime:ClockTime
		// failed:  nil
	};
	void rpc_Set(rpc::request<Set>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct ReplicateSet : rpc::message<32, 0, rpc::basic_session> {
		Clock adjust_clock;
		replicate_flags flags;
		msgtype::DBKey dbkey;
		msgtype::DBValue dbval;
		void msgpack_unpack(const msgpack::type::tuple<
				Clock, replicate_flags, msgtype::DBKey, msgtype::DBValue >& args)
		{
			this->adjust_clock = args.get<0>();
			this->flags = args.get<1>();
			this->dbkey = args.get<2>();
			this->dbval = args.get<3>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(4);
			pk.pack(adjust_clock);
			pk.pack(flags);
			pk.pack(dbkey);
			pk.pack(dbval);
		}
		typedef rpc::retry<ReplicateSet> retry;
		ReplicateSet(
				const Clock& adjust_clock_,
				const replicate_flags& flags_,
				const msgtype::DBKey& dbkey_,
				const msgtype::DBValue& dbval_) :
				adjust_clock(adjust_clock_), flags(flags_), dbkey(dbkey_), dbval(dbval_) { }
		ReplicateSet() { }

		// success: true
		// ignored: false
	};
	void rpc_ReplicateSet(rpc::request<ReplicateSet>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct GetIfModified : rpc::message<37, 0, rpc::basic_session> {
		msgtype::DBKey dbkey;
		ClockTime if_time;
		void msgpack_unpack(const msgpack::type::tuple<
				msgtype::DBKey, ClockTime >& args)
		{
			this->dbkey = args.get<0>();
			this->if_time = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(dbkey);
			pk.pack(if_time);
		}
		typedef rpc::retry<GetIfModified> retry;
		GetIfModified(
				const msgtype::DBKey& dbkey_,
				const ClockTime& if_time_) :
				dbkey(dbkey_), if_time(if_time_) { }
		GetIfModified() { }

		// success: value:DBValue
		// not-modified: true  // FIXME ClockTime?
		// not found: nil
	};
	void rpc_GetIfModified(rpc::request<GetIfModified>&, rpc::auto_zone z,
			rpc::weak_responder);

	struct Delete : rpc::message<36, 0, rpc::basic_session> {
		store_flags flags;
		msgtype::DBKey dbkey;
		void msgpack_unpack(const msgpack::type::tuple<
				store_flags, msgtype::DBKey >& args)
		{
			this->flags = args.get<0>();
			this->dbkey = args.get<1>();
		}

		template <typename Packer>
		void msgpack_pack(Packer& pk) const
		{
			pk.pack_array(2);
			pk.pack(flags);
			pk.pack(dbkey);
		}
		typedef rpc::retry<Delete> retry;
		Delete(
				const store_flags& flags_,
				const msgtype::DBKey& dbkey_) :
				flags(flags_), dbkey(dbkey_) { }
		Delete() { }

		// success: true
		// not foud: false
		// failed: nil
	};
	void rpc_Delete(rpc::request<Delete>&, rpc::auto_zone z,
			rpc::weak_responder);

private:
	static void check_replicator_assign(HashSpace& hs, uint64_t h);
	static void check_coordinator_assign(HashSpace& hs, uint64_t h);

	static void calc_replicators(uint64_t h,
			shared_node* rrepto, unsigned int* rrep_num,
			shared_node* wrepto, unsigned int* wrep_num);

	RPC_REPLY_DECL(ReplicateSet, from, res, err, z,
			rpc::retry<ReplicateSet>* retry,
			volatile unsigned int* copy_required,
			rpc::weak_responder response, ClockTime clocktime);

	RPC_REPLY_DECL(ReplicateDelete, from, res, err, z,
			rpc::retry<ReplicateDelete>* retry,
			volatile unsigned int* copy_required,
			rpc::weak_responder response, bool deleted);
};





}  // namespace server
}  // namespace kumo

#endif
