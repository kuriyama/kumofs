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
#ifndef RPC_ADDRESS_H__
#define RPC_ADDRESS_H__

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <msgpack.hpp>

namespace rpc {


class address {
public:
	address();
	address(const struct sockaddr_in& addr);
#ifdef KUMO_IPV6
	address(const struct sockaddr_in6& addr);
#endif
	address(const char* ptr, unsigned int len);
//	address(const address& o);

public:
	unsigned int dump_size() const;
	const char* dump() const;

	static const unsigned int MAX_DUMP_SIZE = 22;

	bool connectable() const;

private:
	// +--+----+
	// | 2|  4 |
	// +--+----+
	// port network byte order
	//    IPv4 address
	//
	// +--+----------------+----+
	// | 2|       16       |  4 |
	// +--+----------------+----+
	// port network byte order
	//    IPv6 address
	//                     scope id
#ifdef KUMO_IPV6
	char m_serial_address[22];
	unsigned int m_serial_length;  // 6 or 22
#else
	char m_serial_address[8];
#endif

public:
	socklen_t addrlen() const;
	void getaddr(sockaddr* addrbuf) const;
	uint16_t port() const;
	void set_port(uint16_t p);
private:
	uint16_t raw_port() const;

public:
	bool operator== (const address& addr) const;
	bool operator!= (const address& addr) const;
	bool operator<  (const address& addr) const;
	bool operator>  (const address& addr) const;

	friend std::ostream& operator<< (std::ostream& stream, const address& addr);
};

std::ostream& operator<< (std::ostream& stream, const address& addr);


inline address::address()
#ifdef KUMO_IPV6
	: m_serial_length(0)
{
	*((uint16_t*)&m_serial_address[0]) = 0;
}
#else
{
	memset(&m_serial_address[0], 0, 8);
}
#endif

//inline address::address(const address& o) :
//	m_serial_length(o.m_serial_length)
//{
//	memcpy(m_serial_address, o.m_serial_address, m_serial_length);
//}

inline uint16_t address::raw_port() const
{
#ifdef KUMO_IPV6
	return *((uint16_t*)&m_serial_address[0]);
#else
	return *((uint16_t*)&m_serial_address[0]);
#endif
}

inline unsigned int address::dump_size() const
{
#ifdef KUMO_IPV6
	return m_serial_length;
#else
	return 6;
#endif
}
inline const char* address::dump() const
{
#ifdef KUMO_IPV6
	return m_serial_address;
#else
	return m_serial_address;
#endif
}

inline uint16_t address::port() const
{
	return ntohs(raw_port());
}

inline void address::set_port(uint16_t p)
{
#ifdef KUMO_IPV6
	*((uint16_t*)m_serial_address) = htons(p);
#else
	*((uint16_t*)m_serial_address) = htons(p);
#endif
}

inline bool address::connectable() const
{
	return raw_port() != 0;
}

inline socklen_t address::addrlen() const
{
#ifdef KUMO_IPV6
	return m_serial_length == 6 ?
		sizeof(sockaddr_in) : sizeof(sockaddr_in6);
#else
	return sizeof(sockaddr_in);
#endif
}

inline bool address::operator== (const address& addr) const
{
#ifdef KUMO_IPV6
	return m_serial_length == addr.m_serial_length &&
		memcmp(m_serial_address, addr.m_serial_address, m_serial_length) == 0;
#else
	return memcmp(m_serial_address, addr.m_serial_address, 8) == 0;
#endif
}

inline bool address::operator!= (const address& addr) const
{
	return !(*this == addr);
}

inline bool address::operator< (const address& addr) const
{
#ifdef KUMO_IPV6
	if(m_serial_length == addr.m_serial_length) {
		return memcmp(m_serial_address, addr.m_serial_address, m_serial_length) < 0;
	} else {
		return m_serial_length < addr.m_serial_length;
	}
#else
	return memcmp(m_serial_address, addr.m_serial_address, 8) < 0;
#endif
}

inline bool address::operator> (const address& addr) const
{
#ifdef KUMO_IPV6
	if(m_serial_length == addr.m_serial_length) {
		return memcmp(m_serial_address, addr.m_serial_address, m_serial_length) > 0;
	} else {
		return m_serial_length > addr.m_serial_length;
	}
#else
	return memcmp(m_serial_address, addr.m_serial_address, 8) > 0;
#endif
}


#ifdef MSGPACK_OBJECT_HPP__
inline address& operator>> (msgpack::object o, address& v)
{
	using namespace msgpack;
	if(o.type != type::RAW) { throw type_error(); }
	v = address(o.via.raw.ptr, o.via.raw.size);
	return v;
}

template <typename Stream>
inline msgpack::packer<Stream>& operator<< (msgpack::packer<Stream>& o, const address& v)
{
	using namespace msgpack;
	o.pack_raw(v.dump_size());
	o.pack_raw_body(v.dump(), v.dump_size());
	return o;
}
#endif


}  // namespace rpc


#endif /* rpc/address.h */

