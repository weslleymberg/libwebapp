SUBDIRS = src

test: all
	gcc test/run_all_tests.c test/test_http_messages.c test/test_hash.c test/test_iterator.c src/http_messages.c src/hash.c src/iterator.c -lcunit -o run_all_tests
	./run_all_tests
