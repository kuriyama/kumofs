
noinst_LIBRARIES = libkumo_rpc.a libkumo_cluster.a

libkumo_rpc_a_CPPFLAGS = -I..

libkumo_cluster_a_CPPFLAGS = -I..

libkumo_rpc_a_SOURCES = \
		address.cc \
		session.cc

libkumo_cluster_a_SOURCES = \
		$(libkumo_rpc_a_SOURCES) \
		server.cc \
		cluster.cc

noinst_HEADERS = \
		address.h \
		client.h \
		client_tmpl.h \
		cluster.h \
		connection.h \
		exception.h \
		message.h \
		protocol.h \
		request.h \
		responder.h \
		responder_impl.h \
		retry.h \
		rpc.h \
		server.h \
		session.h \
		session_impl.h \
		transport.h \
		transport_impl.h \
		types.h \
		vrefbuffer.h \
		wavy.h \
		weak_responder.h \
		weak_responder_impl.h

