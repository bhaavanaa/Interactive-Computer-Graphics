# Using built-in functions in Opencv , draw polygon with 5 vertices of your choice and then
# do the following and display the results-
# a. Translate the polygon with vector (a,b)
# b. Rotate the polygon with given theta
# c. Scale the polygon with the given scaling factor


import cv2
import numpy as np

image = cv2.imread('/home/dell/semester_7/Computer_graphics/Lab/lab_10/pentagon.jpeg') 
rows, cols = image.shape[:2] 


### Translation
M = np.float32([[1,0,200], [0,1,100]])
translate = cv2.warpAffine(image, M, (cols,rows))


# Rotation
M = cv2.getRotationMatrix2D((cols/2,rows/2), 120, 1)
rotate = cv2.warpAffine(image, M, (cols,rows))


# Scaling
scale = cv2.resize(image, None, fx=1.5, fy=1.5, interpolation = cv2.INTER_CUBIC)	


cv2.imshow('original image', image)
cv2.imshow('translation', translate)
cv2.imshow('rotation', rotate)
cv2.imshow('scaling', scale)
cv2.waitKey(0)
cv2.destroyAllWindows() 
