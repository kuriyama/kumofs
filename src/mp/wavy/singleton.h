//
// mp::wavy
//
// Copyright (C) 2008 FURUHASHI Sadayuki
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

#ifndef MP_WAVY_SINGLETON_H__
#define MP_WAVY_SINGLETON_H__

#include "mp/wavy/core.h"
#include "mp/wavy/output.h"

namespace mp {
namespace wavy {


template <typename Instance>
struct singleton {

	typedef core::handler handler;
	typedef output::finalize_t finalize_t;
	typedef output::request request;

	static void initialize(size_t core_thread, size_t output_thread);

	static void add_core_thread(size_t num);
	static void add_output_thread(size_t num);

	static void join();
	static void detach();
	static void end();

	static void write(int fd, const char* buf, size_t buflen);
	static void writev(int fd, const iovec* vec, size_t veclen);

	static void write(int fd, const char* buf, size_t buflen, request req);
	static void write(int fd, const char* buf, size_t buflen, finalize_t finalize, void* user);
	static void writev(int fd, const iovec* vec, size_t veclen, request req);
	static void writev(int fd, const iovec* vec, size_t veclen, finalize_t finalize, void* user);

	static void writev(int fd, const iovec* bufvec, const request* reqvec, size_t veclen);


	typedef core::connect_callback_t connect_callback_t;
	static void connect(
			int socket_family, int socket_type, int protocol,
			const sockaddr* addr, socklen_t addrlen,
			int timeout_msec, connect_callback_t callback);


	typedef core::listen_callback_t listen_callback_t;
	static void listen(int lsock, listen_callback_t callback);


	typedef core::timer_callback_t timer_callback_t;
	static void timer(const timespec* interval, timer_callback_t callback);


	template <typename Handler>
	static Handler* add(int fd);
	template <typename Handler, typename A1>
	static Handler* add(int fd, A1 a1);
	template <typename Handler, typename A1, typename A2>
	static Handler* add(int fd, A1 a1, A2 a2);
	template <typename Handler, typename A1, typename A2, typename A3>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	static Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15);

	template <typename F>
	static void submit(F f);
	template <typename F, typename A1>
	static void submit(F f, A1 a1);
	template <typename F, typename A1, typename A2>
	static void submit(F f, A1 a1, A2 a2);
	template <typename F, typename A1, typename A2, typename A3>
	static void submit(F f, A1 a1, A2 a2, A3 a3);
	template <typename F, typename A1, typename A2, typename A3, typename A4>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	static void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15);

private:
	static core* s_core;
	static output* s_output;

	singleton();
};

template <typename Instance>
core* singleton<Instance>::s_core;

template <typename Instance>
output* singleton<Instance>::s_output;

template <typename Instance>
void singleton<Instance>::initialize(size_t core_thread, size_t output_thread)
{
	s_core = new core();
	s_output = new output();
	add_core_thread(core_thread);
	add_output_thread(output_thread);
}

template <typename Instance>
void singleton<Instance>::add_core_thread(size_t num)
	{ s_core->add_thread(num); }

template <typename Instance>
void singleton<Instance>::add_output_thread(size_t num)
	{ s_output->add_thread(num); }

template <typename Instance>
void singleton<Instance>::join()
{
	s_core->join();
	s_output->join();
}

template <typename Instance>
void singleton<Instance>::detach()
{
	s_core->detach();
	s_output->detach();
}

template <typename Instance>
void singleton<Instance>::end()
{
	s_core->end();
	s_output->end();
}

template <typename Instance>
inline void singleton<Instance>::write(int fd, const char* buf, size_t buflen)
	{ s_output->write(fd, buf, buflen); }

template <typename Instance>
inline void singleton<Instance>::writev(int fd, const iovec* vec, size_t veclen)
	{ s_output->writev(fd, vec, veclen); }

template <typename Instance>
inline void singleton<Instance>::write(int fd, const char* buf, size_t buflen, request req)
	{ s_output->write(fd, buf, buflen, req); }

template <typename Instance>
inline void singleton<Instance>::write(int fd, const char* buf, size_t buflen, finalize_t finalize, void* user)
	{ s_output->write(fd, buf, buflen, finalize, user); }

template <typename Instance>
inline void singleton<Instance>::writev(int fd, const iovec* vec, size_t veclen, request req)
	{ s_output->writev(fd, vec, veclen, req); }

template <typename Instance>
inline void singleton<Instance>::writev(int fd, const iovec* vec, size_t veclen, finalize_t finalize, void* user)
	{ s_output->writev(fd, vec, veclen, finalize, user); }

template <typename Instance>
inline void singleton<Instance>::writev(int fd, const iovec* bufvec, const request* reqvec, size_t veclen)
	{ s_output->writev(fd, bufvec, reqvec, veclen); }


template <typename Instance>
inline void singleton<Instance>::connect(
		int socket_family, int socket_type, int protocol,
		const sockaddr* addr, socklen_t addrlen,
		int timeout_msec, connect_callback_t callback)
{
	s_core->connect(socket_family, socket_type, protocol,
			addr, addrlen, timeout_msec, callback);
}


template <typename Instance>
inline void singleton<Instance>::listen(int lsock, listen_callback_t callback)
	{ s_core->listen(lsock, callback); }


template <typename Instance>
inline void singleton<Instance>::timer(
		const timespec* interval, timer_callback_t callback)
	{ s_core->timer(interval, callback); }


template <typename Instance>
template <typename Handler>
inline Handler* singleton<Instance>::add(int fd)
	{ return s_core->add<Handler>(fd); }
template <typename Instance>
template <typename Handler, typename A1>
inline Handler* singleton<Instance>::add(int fd, A1 a1)
	{ return s_core->add<Handler, A1>(fd, a1); }
template <typename Instance>
template <typename Handler, typename A1, typename A2>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2)
	{ return s_core->add<Handler, A1, A2>(fd, a1, a2); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3)
	{ return s_core->add<Handler, A1, A2, A3>(fd, a1, a2, a3); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4)
	{ return s_core->add<Handler, A1, A2, A3, A4>(fd, a1, a2, a3, a4); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5>(fd, a1, a2, a3, a4, a5); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6>(fd, a1, a2, a3, a4, a5, a6); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7>(fd, a1, a2, a3, a4, a5, a6, a7); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8>(fd, a1, a2, a3, a4, a5, a6, a7, a8); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); }
template <typename Instance>
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
inline Handler* singleton<Instance>::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15)
	{ return s_core->add<Handler, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }

template <typename Instance>
template <typename F>
inline void singleton<Instance>::submit(F f)
	{ s_core->submit<F>(f); }
template <typename Instance>
template <typename F, typename A1>
inline void singleton<Instance>::submit(F f, A1 a1)
	{ s_core->submit<F, A1>(f, a1); }
template <typename Instance>
template <typename F, typename A1, typename A2>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2)
	{ s_core->submit<F, A1, A2>(f, a1, a2); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3)
	{ s_core->submit<F, A1, A2, A3>(f, a1, a2, a3); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4)
	{ s_core->submit<F, A1, A2, A3, A4>(f, a1, a2, a3, a4); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
	{ s_core->submit<F, A1, A2, A3, A4, A5>(f, a1, a2, a3, a4, a5); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6>(f, a1, a2, a3, a4, a5, a6); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7>(f, a1, a2, a3, a4, a5, a6, a7); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8>(f, a1, a2, a3, a4, a5, a6, a7, a8); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); }
template <typename Instance>
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
inline void singleton<Instance>::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15)
	{ s_core->submit<F, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }


}  // namespace wavy
}  // namespace mp

#endif /* mp/wavy/singleton.h */

