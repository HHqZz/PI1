progmem -v -o sequence.bin sequence.bc
make -C ../gerMem/ecrireMem
make install -C ../gerMem/ecrireMem
serieViaUSB -h -e -f sequence.bin
make
make install
