g++ main.cpp -o output
wait
./output building.raw buildingX.raw
wait
rawtopgm 500 500 testpatternnew.raw > testpatternnew.pgm
wait
ppmtogif < testpatternnew.pgm > testpatternnew.gif
ls
