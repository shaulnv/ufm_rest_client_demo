#!/bin/bash

echo please make sure you run ./echo_server.py first, so this client can talk to it

./build/Release/ufm_client_cli "$@"
