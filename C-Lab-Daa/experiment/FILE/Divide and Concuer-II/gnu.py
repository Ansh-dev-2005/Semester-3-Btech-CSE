import subprocess
import os

# Remove the existing plot.png if it exists
if os.path.exists('plot.png'):
    os.remove('plot.png')

# Gnuplot script to plot data
gnuplot_script = """
set terminal png
set output 'plot.png'
set title 'Data Plot'
set xlabel 'X-axis'
set ylabel 'Y-axis'
plot 'output.txt' with lines
"""

# Write the Gnuplot script to a temporary file
with open('gnuplot_script.gp', 'w') as script_file:
    script_file.write(gnuplot_script)

# Run Gnuplot using subprocess with error handling
try:
    subprocess.check_call(['gnuplot', 'gnuplot_script.gp'])
    print("Graph plotted successfully. Output saved as 'plot.png'")
except subprocess.CalledProcessError as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"An error occurred: {e}")
