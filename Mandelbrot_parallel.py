import time
from PIL import Image
from multiprocessing import Pool
def fill_row(y):
    max_iterations = 255
    image_of_x = 1024
    image_of_y = 1024
    x1 = -2.0
    x2 = 1.0
    y1 = -1.5
    y2 = 1.5
    zy = y * (y2 - y1) / (image_of_y - 1) + y1
    values = [[]]
    for x in range(1024):
        zx = x * (x2 - x1) / (image_of_x - 1) + x1
        z = zx + zy * 1j
        c = z
        for i in range(max_iterations):
            if abs(z) > 2.0: break
            z = z * z + c
        values.append([x, y, i])
    return values

if __name__ == '__main__':
    max_iterations = 255
    image_of_x = 1024
    image_of_y = 1024
    start = time.process_time()
    image = Image.new("RGB", (image_of_x, image_of_y))
    pool = Pool()
    data_outputs = pool.map(fill_row, range(image_of_y))
    #első Y második X+1 hamradik xyz váltó
    for a in range(1023):
        for b in range(1023):
            x = b
            y = a + 1
            i= data_outputs[a+1][b+1][2]
            image.putpixel((x, y), (i % 4 * 64, i % 8 * 32, i % 16 * 16))
    stop = time.process_time()
    print(f'Idő: {stop - start}')
    image.show()
