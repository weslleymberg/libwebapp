SUBDIRS = src

test: all
	gcc test/run_all_tests.c test/test_http_messages.c test/test_hash.c src/http_messages.c src/hash.c -lcunit -o run_all_tests
	./run_all_tests
