//
// mp::wavy::core
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

#ifndef MP_WAVY_CORE_H__
#define MP_WAVY_CORE_H__

#include "mp/functional.h"
#include "mp/memory.h"
#include "mp/pthread.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <memory>
#include <queue>

namespace mp {
namespace wavy {


class core {
public:
	core();
	~core();

	void add_thread(size_t num);

	void end();
	bool is_end() const;

	void join();
	void detach();


	struct handler {
		handler(int fd) : m_fd(fd) { }
		virtual ~handler() { ::close(m_fd); }
		virtual void read_event() = 0;

		int fd() const { return m_fd; }

		template <typename IMPL>
		shared_ptr<IMPL> shared_self()
		{
			return static_pointer_cast<IMPL>(*m_shared_self);
		}

	private:
		int m_fd;
		shared_ptr<handler>* m_shared_self;
		friend class core;
	};

	typedef function<void (int fd, int err)> connect_callback_t;
	void connect(int socket_family, int socket_type, int protocol,
			const sockaddr* addr, socklen_t addrlen,
			int timeout_msec, connect_callback_t callback);


	typedef function<void (int fd, int err)> listen_callback_t;
	void listen(int lsock, listen_callback_t callback);


	typedef function<void ()> timer_callback_t;
	void timer(const timespec* interval, timer_callback_t callback);


	template <typename Handler>
	Handler* add(int fd);
	template <typename Handler, typename A1>
	Handler* add(int fd, A1 a1);
	template <typename Handler, typename A1, typename A2>
	Handler* add(int fd, A1 a1, A2 a2);
	template <typename Handler, typename A1, typename A2, typename A3>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14);
	template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	Handler* add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15);

	template <typename F>
	void submit(F f);
	template <typename F, typename A1>
	void submit(F f, A1 a1);
	template <typename F, typename A1, typename A2>
	void submit(F f, A1 a1, A2 a2);
	template <typename F, typename A1, typename A2, typename A3>
	void submit(F f, A1 a1, A2 a2, A3 a3);
	template <typename F, typename A1, typename A2, typename A3, typename A4>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14);
	template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	void submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15);

private:
	void add_impl(int fd, handler* newh);

	typedef function<void ()> task_t;
	void submit_impl(task_t f);

private:
	class impl;
	const std::auto_ptr<impl> m_impl;

	core(const core&);
};

typedef core::handler handler;


template <typename Handler>
Handler* core::add(int fd)
	{ Handler* h = new Handler(fd); add_impl(fd, h); return h; }
template <typename Handler, typename A1>
Handler* core::add(int fd, A1 a1)
	{ Handler* h = new Handler(fd, a1); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2>
Handler* core::add(int fd, A1 a1, A2 a2)
	{ Handler* h = new Handler(fd, a1, a2); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3)
	{ Handler* h = new Handler(fd, a1, a2, a3); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); add_impl(fd, h); return h; }
template <typename Handler, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
Handler* core::add(int fd, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15)
	{ Handler* h = new Handler(fd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); add_impl(fd, h); return h; }

template <typename F>
inline void core::submit(F f)
	{ submit_impl(task_t(f)); }
template <typename F, typename A1>
inline void core::submit(F f, A1 a1)
	{ submit_impl(bind(f, a1)); }
template <typename F, typename A1, typename A2>
inline void core::submit(F f, A1 a1, A2 a2)
	{ submit_impl(bind(f, a1, a2)); }
template <typename F, typename A1, typename A2, typename A3>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3)
	{ submit_impl(bind(f, a1, a2, a3)); }
template <typename F, typename A1, typename A2, typename A3, typename A4>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4)
	{ submit_impl(bind(f, a1, a2, a3, a4)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14)); }
template <typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
inline void core::submit(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15)
	{ submit_impl(bind(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)); }


}  // namespace wavy
}  // namespace mp

#endif /* mp/wavy/core.h */

