# Download Lena image, and write code in Python/Matlab to crop and display the middle half of the image

import cv2
import numpy as np

img = cv2.imread("lena.jpg")

X = img.shape[0]	
Y = img.shape[1]

crop_img = [[[0, 0, 0] for i in range(Y)] for j in range(X)]

x1 = X/4
y1 = Y/4
x2 = X-X/4
y2 = Y-Y/4

for i in range(X):
	for j in range(Y):
		if(x1<i and i<x2 and y1<j and j<y2):
			crop_img[i][j] = img[i][j]

lena = np.array(crop_img, dtype = 'uint8')
cv2.imwrite("crop_lena.jpg", lena)