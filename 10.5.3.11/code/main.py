import matplotlib.pyplot as plt

# Read data from the DAT file
data = []
with open('output.dat', 'r') as file:
    for line in file:
        line = line.strip().split('\t')
        data.append([int(line[0]), int(line[1])])

# Separate x and y values
x = [entry[0] for entry in data]
y = [entry[1] for entry in data]

# Plot the data as stems
plt.stem(x, y, use_line_collection=True)
plt.xlabel('n')
plt.ylabel('y(n)')
plt.title('Convolution of x(n) and u(n)')
plt.grid(True)

save_path = 'main.png'  # Update this path
plt.savefig(save_path)
