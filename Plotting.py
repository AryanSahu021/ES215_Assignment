import matplotlib.pyplot as plt
import numpy as np

# Data provided
N_values = [64, 128, 256, 512, 1024]

cpp_full_sys_int = [0.00413165, 0.0287276, 0.190968, 1.56744, 12.0566]
cpp_full_cpu_int = [0.0041196, 0.0287274, 0.19085, 1.54718, 11.9539]
cpp_full_sys_double = [0.00339137, 0.0276951, 0.192108, 1.5321, 12.5799]
cpp_full_cpu_double = [0.00339092, 0.0276333, 0.192101, 1.52917, 12.5006]

cpp_meat_sys_int = [0.00395975, 0.0282728, 0.189297, 1.56033, 12.0286]
cpp_meat_cpu_int = [0.00395988, 0.0282729, 0.18918, 1.54006, 11.9262]
cpp_meat_sys_double = [0.00323555, 0.0271645, 0.1902, 1.52319, 12.5458]
cpp_meat_cpu_double = [0.00323539, 0.0271032, 0.190193, 1.52027, 12.4665]

python_full_sys_int = [0.553517, 1.521046, 11.869255, 95.05253, 764.266939]
python_full_cpu_int = [0.190075, 1.499579, 11.779261, 94.589806, 759.269645]
python_full_sys_double = [0.174865, 1.382371, 11.806968, 93.834993, 754.899908]
python_full_cpu_double = [0.174024, 1.3812, 11.755139, 93.382377, 750.610768]

python_meat_sys_int = [0.175218, 1.520642, 11.867545, 95.046071, 764.246552]
python_meat_cpu_int = [0.175187, 1.499178, 11.777554, 94.583349, 759.249259]
python_meat_sys_double = [0.174685, 1.381856, 11.80547, 93.829488, 754.88091]
python_meat_cpu_double = [0.173845, 1.380686, 11.753643, 93.376873, 750.59177]

# Plotting

plt.figure(figsize=(14, 12))

# CPP Full Integer
plt.subplot(4, 2, 1)
plt.plot(N_values, cpp_full_sys_int, label='CPP Full System Time (Int)', marker='o')
plt.plot(N_values, cpp_full_cpu_int, label='CPP Full CPU Time (Int)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('CPP Full Integer Multiplication Times')
plt.legend()
plt.grid(True)

# CPP Full Double
plt.subplot(4, 2, 2)
plt.plot(N_values, cpp_full_sys_double, label='CPP Full System Time (Double)', marker='o')
plt.plot(N_values, cpp_full_cpu_double, label='CPP Full CPU Time (Double)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('CPP Full Double Multiplication Times')
plt.legend()
plt.grid(True)

# CPP Meat Integer
plt.subplot(4, 2, 3)
plt.plot(N_values, cpp_meat_sys_int, label='CPP Meat System Time (Int)', marker='o')
plt.plot(N_values, cpp_meat_cpu_int, label='CPP Meat CPU Time (Int)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('CPP Meat Integer Multiplication Times')
plt.legend()
plt.grid(True)

# CPP Meat Double
plt.subplot(4, 2, 4)
plt.plot(N_values, cpp_meat_sys_double, label='CPP Meat System Time (Double)', marker='o')
plt.plot(N_values, cpp_meat_cpu_double, label='CPP Meat CPU Time (Double)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('CPP Meat Double Multiplication Times')
plt.legend()
plt.grid(True)

# Python Full Integer
plt.subplot(4, 2, 5)
plt.plot(N_values, python_full_sys_int, label='Python Full System Time (Int)', marker='o')
plt.plot(N_values, python_full_cpu_int, label='Python Full CPU Time (Int)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('Python Full Integer Multiplication Times')
plt.legend()
plt.grid(True)

# Python Full Double
plt.subplot(4, 2, 6)
plt.plot(N_values, python_full_sys_double, label='Python Full System Time (Double)', marker='o')
plt.plot(N_values, python_full_cpu_double, label='Python Full CPU Time (Double)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('Python Full Double Multiplication Times')
plt.legend()
plt.grid(True)

# Python Meat Integer
plt.subplot(4, 2, 7)
plt.plot(N_values, python_meat_sys_int, label='Python Meat System Time (Int)', marker='o')
plt.plot(N_values, python_meat_cpu_int, label='Python Meat CPU Time (Int)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('Python Meat Integer Multiplication Times')
plt.legend()
plt.grid(True)

# Python Meat Double
plt.subplot(4, 2, 8)
plt.plot(N_values, python_meat_sys_double, label='Python Meat System Time (Double)', marker='o')
plt.plot(N_values, python_meat_cpu_double, label='Python Meat CPU Time (Double)', marker='o')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.title('Python Meat Double Multiplication Times')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

