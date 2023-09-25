import matplotlib.pyplot as plt

# Read data from the text file
with open("./matrix_multiply_times.txt", "r") as file:
    lines = file.readlines()
    sizes = []
    normal_times = []
    strassen_times = []
    for line in lines:
        n, normal_time, strassen_time = map(float, line.strip().split())
        sizes.append(n)
        normal_times.append(normal_time)
        strassen_times.append(strassen_time)

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(sizes, normal_times, marker='o', label='Standard Multiplication')
plt.plot(sizes, strassen_times, marker='o', label="Strassen's Multiplication")
plt.xlabel('Matrix Size (n)')
plt.ylabel('Time (seconds)')
plt.title('Matrix Multiplication Time Comparison')
plt.legend()
plt.grid()
plt.show()
