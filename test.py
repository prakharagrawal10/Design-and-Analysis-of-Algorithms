import time

start_time = time.time()

count = 0
for i in range(1, 10000001):
    count += 1

end_time = time.time()

print("Counting to one million took {:.6f} seconds.".format(end_time - start_time))
