import cv2
import numpy as np



def simulate_printer_P1(img, X, Y):
	B1 = [[0 for i in range(Y)] for j in range(X)]
	f1 = [[0 for i in range(Y)] for j in range(X)]
	
	for i in range(X):
		for j in range(Y):
			f = 0.299*img[i][j][0] + 0.587*img[i][j][1] + 0.114*img[i][j][2]
			f1[i][j] = f
			if(f <= 127):
				B1[i][j] = 0
			else:
				B1[i][j] = 255

	return(f1, B1)

	

def simulate_printer_P2(img, X, Y):
	img1 = [[0 for i in range(Y)] for j in range(X)]
	img2 = [[0 for i in range(Y)] for j in range(X)]
	P = [[0 for i in range(Y)] for j in range(X)]

	for i in range(X):
		for j in range(Y):
			img1[i][j] = 0.299*img[i][j][0] + 0.587*img[i][j][1] + 0.114*img[i][j][2]
			img2[i][j] = img1[i][j]
			if(img2[i][j] <= 127):
				P[i][j] = 0
			else:
				P[i][j] = 255

	a = 3/8
	b = 2/8
	c = 3/8

	for i in range(X):
		for j in range(Y):
			e = img2[i][j] - P[i][j]

			if(i==X-1 and j<Y-1):
				img2[i][j+1] += e
				if(img2[i][j+1] <= 127):
					P[i][j+1] = 0
				else:
					P[i][j+1] = 255

			elif(i<X-1 and j==Y-1): 
				img2[i+1][j] += e
				if(img2[i+1][j] <= 127):
					P[i+1][j] = 0
				else:
					P[i+1][j] = 255

			elif(i<X-1 and j<Y-1): 
				
				img2[i+1][j] += a*e
				img2[i+1][j+1] += b*e
				img2[i][j+1] += c*e
				if(img2[i+1][j] <= 127):
					P[i+1][j] = 0
				else:
					P[i+1][j] = 255
				if(img2[i+1][j+1] <= 127):
					P[i+1][j+1] = 0
				else:
					P[i+1][j+1] = 255
				if(img2[i][j+1] <= 127):
					P[i][j+1] = 0
				else:
					P[i][j+1] = 255
	
	return(P)



def avg_filter(img1):
	avg_fil = [[1/9 for i in range(3)] for j in range(3)]
	m = len(img1)
	n = len(img1[0])
	
	a = 3
	b = 3

	cor_mat=[[0 for i in range(n+b-1)] for j in range(m+a-1)]
	cor_mat1=[[0 for i in range(n)] for j in range(m)]
	
	for x in range(m+a-1):
		for y in range(n+b-1):
			sum1 = 0
			for j in range(int(-(b-1)/2), int((b-1)/2)):
				sum2 = 0
				for i in range(int(-(a-1)/2), int((a-1)/2)):
					if(x+i < m and y+j < n):
						sum2 = sum2 + img1[x+i][y+j]*avg_fil[i][j]
				sum1 += sum2
			cor_mat[x][y] = sum1
	
	g = 0
	h = 0
	for i in range(1, m+a-2):
		h = 0
		for j in range(1, n+b-2):
			cor_mat1[g][h] = cor_mat[i][j]
			h +=1
		g+=1

	return(cor_mat1)
	


def absolute(x):
	if(x<0):
		return(-x)
	else:
		return(x)

	
img = cv2.imread("lena.jpg")

X = img.shape[0]	
Y = img.shape[1]	
# print(X, Y)

f1, B1 = simulate_printer_P1(img, X, Y)
B2 = simulate_printer_P2(img, X, Y)

f1_lena = np.array(f1, dtype = 'uint8')
cv2.imwrite("f1_lena.jpg", f1_lena)

P1_lena = np.array(B1, dtype = 'uint8')
cv2.imwrite("P1_lena_B1.jpg", P1_lena)

P2_lena = np.array(B2, dtype = 'uint8')
cv2.imwrite("P2_lena_B2.jpg", P2_lena)
# print(P)


abs_error_f1_B1 = [[0 for i in range(Y)] for j in range(X)]
abs_error_f1_B2 = [[0 for i in range(Y)] for j in range(X)]

for i in range(X):
	for j in range(Y):
		abs_error_f1_B1[i][j] = absolute(f1[i][j] - B1[i][j])
		abs_error_f1_B2[i][j] = absolute(f1[i][j] - B2[i][j])

avg_abs_error_f1_B1 = avg_filter(abs_error_f1_B1)
avg_abs_error_f1_B2 = avg_filter(abs_error_f1_B2)

print("The local average absolute difference between f1 and B1 is-")
print(avg_abs_error_f1_B1[0][0])

error_f1_B1_lena = np.array(avg_abs_error_f1_B1, dtype = 'uint8')
cv2.imwrite("abs_error_f1_B1.jpg", error_f1_B1_lena)

print("The local average absolute difference between f1 and B2 is-")
print(avg_abs_error_f1_B2[0][0])

error_f1_B2_lena = np.array(avg_abs_error_f1_B2, dtype = 'uint8')
cv2.imwrite("abs_error_f1_B2.jpg", error_f1_B2_lena)
