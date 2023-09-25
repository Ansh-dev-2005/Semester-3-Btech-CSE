
set terminal png
set output 'plot.png'
set title 'Data Plot'
set xlabel 'X-axis'
set ylabel 'Y-axis'
plot 'output.txt' with lines
