libwebapp 0.1.0
===============

A library to create a web application with HTML5 websockets.


Installing
----------

To install the lib, run::

    $ cmake .
    $ make
    # make install


Basic usage
-----------

You need to include some header file of libwebapp on your code::

    #include <libwebapp/hash.h>
    #include <stdio.h>

    int main()
    {
        Hash* hash;
        char* value;
        hash = new_hash();
        hash_set(hash, "key", "my value");
        value = hash_get(hash, "key");
        printf("The value is: %s\n", value);
        // it prints "The value is: my value"
        return 0;
    }

And compile with the "-lwebapp" option::

    $ gcc example.c -lwebapp -o example
