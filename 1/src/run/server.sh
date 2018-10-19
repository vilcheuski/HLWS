(cd .. && make)

export LD_LIBRARY_PATH=/usr/local/lib

echo 'Start server...'

../hello -c ../config.json
