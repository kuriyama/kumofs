//
// MessagePack fast log format
//
// Copyright (C) 2008-2009 FURUHASHI Sadayuki
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
#ifndef LOGPACK_HPP__
#define LOGPACK_HPP__

#include <msgpack.hpp>
#include <string>
#include <memory>
#include <stdexcept>
#include "logpack.h"


class logpack {
public:
	struct PSHARED_TAG { };
	logpack(const char* fname);
	logpack(const char* fname, PSHARED_TAG);
	~logpack();

	int reopen();

public:
#define MSGPACK_LOG_BEGIN(NUM) \
	msgpack::sbuffer buf; \
	{ \
		uint64_t zero = 0; \
		buf.write((const char*)&zero, 4); \
	} \
	msgpack::packer<msgpack::sbuffer> m(buf); \
	m.pack_array(3); \
	m.pack_uint32(fixstr(name)); \
	m.pack_uint16(version); \
	m.pack_map(NUM);
#define MSGPACK_LOG_ADD(k, v) \
	m.pack_uint32(fixstr(k)); \
	m << v;
#define MSGPACK_LOG_END \
	char* p = (char*)buf.data(); \
	size_t sz = buf.size(); \
	*(uint32_t*)p = htonl(sz - 4); \
	return write_raw(p, sz);


	template <size_t LN, size_t L1, typename T1>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1)
	{
		MSGPACK_LOG_BEGIN(1);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2)
	{
		MSGPACK_LOG_BEGIN(2);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3)
	{
		MSGPACK_LOG_BEGIN(3);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4)
	{
		MSGPACK_LOG_BEGIN(4);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5)
	{
		MSGPACK_LOG_BEGIN(5);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6)
	{
		MSGPACK_LOG_BEGIN(6);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7)
	{
		MSGPACK_LOG_BEGIN(7);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8)
	{
		MSGPACK_LOG_BEGIN(8);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9)
	{
		MSGPACK_LOG_BEGIN(9);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10)
	{
		MSGPACK_LOG_BEGIN(10);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10, size_t L11, typename T11>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10, const char (&k11)[L11], T11 v11)
	{
		MSGPACK_LOG_BEGIN(11);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_ADD(k11, v11);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10, size_t L11, typename T11, size_t L12, typename T12>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10, const char (&k11)[L11], T11 v11, const char (&k12)[L12], T12 v12)
	{
		MSGPACK_LOG_BEGIN(12);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_ADD(k11, v11);

		MSGPACK_LOG_ADD(k12, v12);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10, size_t L11, typename T11, size_t L12, typename T12, size_t L13, typename T13>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10, const char (&k11)[L11], T11 v11, const char (&k12)[L12], T12 v12, const char (&k13)[L13], T13 v13)
	{
		MSGPACK_LOG_BEGIN(13);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_ADD(k11, v11);

		MSGPACK_LOG_ADD(k12, v12);

		MSGPACK_LOG_ADD(k13, v13);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10, size_t L11, typename T11, size_t L12, typename T12, size_t L13, typename T13, size_t L14, typename T14>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10, const char (&k11)[L11], T11 v11, const char (&k12)[L12], T12 v12, const char (&k13)[L13], T13 v13, const char (&k14)[L14], T14 v14)
	{
		MSGPACK_LOG_BEGIN(14);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_ADD(k11, v11);

		MSGPACK_LOG_ADD(k12, v12);

		MSGPACK_LOG_ADD(k13, v13);

		MSGPACK_LOG_ADD(k14, v14);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10, size_t L11, typename T11, size_t L12, typename T12, size_t L13, typename T13, size_t L14, typename T14, size_t L15, typename T15>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10, const char (&k11)[L11], T11 v11, const char (&k12)[L12], T12 v12, const char (&k13)[L13], T13 v13, const char (&k14)[L14], T14 v14, const char (&k15)[L15], T15 v15)
	{
		MSGPACK_LOG_BEGIN(15);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_ADD(k11, v11);

		MSGPACK_LOG_ADD(k12, v12);

		MSGPACK_LOG_ADD(k13, v13);

		MSGPACK_LOG_ADD(k14, v14);

		MSGPACK_LOG_ADD(k15, v15);

		MSGPACK_LOG_END;
	}

	template <size_t LN, size_t L1, typename T1, size_t L2, typename T2, size_t L3, typename T3, size_t L4, typename T4, size_t L5, typename T5, size_t L6, typename T6, size_t L7, typename T7, size_t L8, typename T8, size_t L9, typename T9, size_t L10, typename T10, size_t L11, typename T11, size_t L12, typename T12, size_t L13, typename T13, size_t L14, typename T14, size_t L15, typename T15, size_t L16, typename T16>
	int write(const char (&name)[LN], uint16_t version, const char (&k1)[L1], T1 v1, const char (&k2)[L2], T2 v2, const char (&k3)[L3], T3 v3, const char (&k4)[L4], T4 v4, const char (&k5)[L5], T5 v5, const char (&k6)[L6], T6 v6, const char (&k7)[L7], T7 v7, const char (&k8)[L8], T8 v8, const char (&k9)[L9], T9 v9, const char (&k10)[L10], T10 v10, const char (&k11)[L11], T11 v11, const char (&k12)[L12], T12 v12, const char (&k13)[L13], T13 v13, const char (&k14)[L14], T14 v14, const char (&k15)[L15], T15 v15, const char (&k16)[L16], T16 v16)
	{
		MSGPACK_LOG_BEGIN(16);

		MSGPACK_LOG_ADD(k1, v1);

		MSGPACK_LOG_ADD(k2, v2);

		MSGPACK_LOG_ADD(k3, v3);

		MSGPACK_LOG_ADD(k4, v4);

		MSGPACK_LOG_ADD(k5, v5);

		MSGPACK_LOG_ADD(k6, v6);

		MSGPACK_LOG_ADD(k7, v7);

		MSGPACK_LOG_ADD(k8, v8);

		MSGPACK_LOG_ADD(k9, v9);

		MSGPACK_LOG_ADD(k10, v10);

		MSGPACK_LOG_ADD(k11, v11);

		MSGPACK_LOG_ADD(k12, v12);

		MSGPACK_LOG_ADD(k13, v13);

		MSGPACK_LOG_ADD(k14, v14);

		MSGPACK_LOG_ADD(k15, v15);

		MSGPACK_LOG_ADD(k16, v16);

		MSGPACK_LOG_END;
	}


private:

	static uint32_t fixstr(const char (&str)[1])
	{ return 0; }

	static uint32_t fixstr(const char (&str)[2])
	{ return 0 | (((uint32_t)str[0])<<(0*8)); }

	static uint32_t fixstr(const char (&str)[3])
	{ return 0 | (((uint32_t)str[0])<<(1*8)) | (((uint32_t)str[1])<<(0*8)); }

	static uint32_t fixstr(const char (&str)[4])
	{ return 0 | (((uint32_t)str[0])<<(2*8)) | (((uint32_t)str[1])<<(1*8)) | (((uint32_t)str[2])<<(0*8)); }

	static uint32_t fixstr(const char (&str)[5])
	{ return 0 | (((uint32_t)str[0])<<(3*8)) | (((uint32_t)str[1])<<(2*8)) | (((uint32_t)str[2])<<(1*8)) | (((uint32_t)str[3])<<(0*8)); }


	int write_raw(char* p, size_t sz);

private:
	logpack_t* m_logpack;

private:
	logpack();
	logpack(const logpack&);
};


inline logpack::logpack(const char* fname)
{
	m_logpack = logpack_new(fname);
	if(!m_logpack) {
		throw std::runtime_error("failed to initialize msgpack::logpack");
	}
}

inline logpack::logpack(const char* fname, PSHARED_TAG)
{
	m_logpack = logpack_new_pshared(fname);
	if(!m_logpack) {
		throw std::runtime_error("failed to initialize msgpack::logpack");
	}
}

inline int logpack::reopen()
{
	return logpack_reopen(m_logpack);
}

inline logpack::~logpack()
{
	logpack_free(m_logpack);
}

inline int logpack::write_raw(char* buf, size_t size)
{
	return logpack_write_raw(m_logpack, buf, size);
}


#endif /* logpack.hpp */

