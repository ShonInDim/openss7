set terminal fig color small portrait fontsize 9 inches size 4.5 2.4
set output 'perftest_cos52_delay.fig'
set nologscale
set ylabel 'Delay (Seconds per Write)'
set y2label '|'
set xlabel 'Write Size (Bytes)'
set grid x y
set key top right Left reverse
#set border 12 lw 0
#set border 3 lw 0.5
set border 3 lw 1
set xtics nomirror (0,256,512,1024,2048,4096,8192)
set ytics nomirror
set tics in
plot \
     'perftest_cos52.dat' using 1:(1/$3) smooth unique title "Streams" with linespoints lt 5,\
     'perftest_cos52.dat' using 1:(1/$4) smooth unique title "Linux" with linespoints lt 3