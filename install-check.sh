#!/bin/sh
set -ex
wget https://github.com/libcheck/check/releases/download/0.11.0/check-0.11.0.tar.gz
tar -xzvf check-0.11.0.tar.gz
cd check-0.11.0 && ./configure --prefix=/usr && make && sudo make install