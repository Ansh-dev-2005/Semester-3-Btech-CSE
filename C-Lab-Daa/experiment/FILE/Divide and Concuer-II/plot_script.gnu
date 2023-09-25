set terminal pngcairo enhanced font "arial,10"
set output "quicksort_performance.png"
set title "Quicksort Performance"
set xlabel "Number of Elements (n)"
set ylabel "Time (seconds)"
set grid
plot "output.txt" using 1:2 with lines title "Execution Time" delimiter " "
