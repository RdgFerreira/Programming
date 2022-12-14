# -*- coding: utf-8 -*-
"""main.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1O2RjOVJcdmJxmkTBlF1rnj0pDPWljK1K
"""

import pandas as pd
import numpy as np
import scipy.io
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
from sklearn.metrics.cluster import adjusted_rand_score
import time

def dist(X, Y, p):
  diff = np.abs(np.array(X) - np.array(Y))
  p_pow = diff ** p
  sum = np.sum(p_pow)
  return sum ** (1/p)

def get_dist_matrix(data, p):
  n = data.shape[0]
  dist_matrix = np.zeros((n, n))

  for i in range(n):
    for j in range(n):
      dist_matrix[i][j] = dist(data.iloc[i], data.iloc[j], p)

  return dist_matrix

def approx_kmeans(dist_matrix, k):
  Centers = np.array([])
  n = dist_matrix.shape[0]
  indexes = np.arange(n)
  new_labels = np.zeros(n)

  first = np.random.randint(n)
  indexes = indexes[indexes != first]
  cluster = 0
  Centers = np.append(Centers, first)
  new_labels[first] = cluster
  cluster += 1

  sum = 0
  max_sum = 0
  idx_max = 0
  size = len(Centers)

  while size < k:
    for i in indexes:
      for j in Centers:
        sum += dist_matrix[i][int(j)]
      if sum >= max_sum:
        max_sum = sum
        idx_max = i
      sum = 0
    indexes = indexes[indexes != idx_max]
    Centers = np.append(Centers, idx_max)
    new_labels[idx_max] = cluster
    cluster += 1
    max_sum = 0
    size = len(Centers)


  min_dist = np.inf

  for i in indexes:
    for j in Centers:
      dist = dist_matrix[i][int(j)]
      if dist <= min_dist:
        min_dist = dist
        new_labels[i] = new_labels[int(j)]
    min_dist = np.inf

  return Centers, new_labels, indexes

def get_max_radius(Centers, indexes, new_labels, dist_matrix):
  max_radius = 0
  curr_max = 0

  for i in Centers:
    label = new_labels[int(i)]
    for j in indexes:
      if new_labels[j] == label:
        dist = dist_matrix[j][int(i)]
        if dist >= curr_max: curr_max = dist
    if curr_max >= max_radius: max_radius = curr_max
    curr_max = 0
  
  return max_radius

dataframes = []
original_labels = []
num_clusters = []
distance_matrices = []

df = pd.read_csv("https://raw.githubusercontent.com/RdgFerreira/ALG2-TP2-Datasets/main/1.csv")
df.loc[df['Class'] == 'Kecimen', 'Class'] = 0
df.loc[df['Class'] == 'Besni', 'Class'] = 1
labels = np.array(df.loc[:, "Class"])
df.drop('Class', axis=1, inplace=True)
dataframes.append(df)
original_labels.append(labels)
num_clusters.append(2)
distance_matrices.append(get_dist_matrix(df, 2))

df = pd.read_csv("https://raw.githubusercontent.com/RdgFerreira/ALG2-TP2-Datasets/main/Absenteeism_at_work.csv")
cols = [0, 1, 2, 3, 4]
df.drop(df.columns[cols], axis=1, inplace=True)
cols = [5]
df.drop(df.columns[cols], axis=1, inplace=True)
cols = [4]
df.drop(df.columns[cols], axis=1, inplace=True)
labels = np.array(df.loc[:, 'Education'])
df.drop('Education', axis=1, inplace=True)
dataframes.append(df)
original_labels.append(labels)
num_clusters.append(4)
distance_matrices.append(get_dist_matrix(df, 2))

df = pd.read_csv('https://raw.githubusercontent.com/RdgFerreira/ALG2-TP2-Datasets/main/ObesityDataSet_raw_and_data_sinthetic.csv')
cols = [5, 6, 7, 8, 10, 15]
df.drop(df.columns[cols], axis=1, inplace=True)
df.loc[df['NObeyesdad'] == 'Insufficient_Weight', 'NObeyesdad'] = 0
df.loc[df['NObeyesdad'] == 'Normal_Weight', 'NObeyesdad'] = 1
df.loc[df['NObeyesdad'] == 'Overweight_Level_I', 'NObeyesdad'] = 2
df.loc[df['NObeyesdad'] == 'Overweight_Level_II', 'NObeyesdad'] = 3
df.loc[df['NObeyesdad'] == 'Obesity_Type_I', 'NObeyesdad'] = 4
df.loc[df['NObeyesdad'] == 'Obesity_Type_II', 'NObeyesdad'] = 5
df.loc[df['NObeyesdad'] == 'Obesity_Type_III', 'NObeyesdad'] = 6
df.loc[df['Gender'] == 'Male', 'Gender'] = 0
df.loc[df['Gender'] == 'Female', 'Gender'] = 1
df.loc[df['family_history_with_overweight'] == 'yes', 'family_history_with_overweight'] = 1
df.loc[df['family_history_with_overweight'] == 'no', 'family_history_with_overweight'] = 0
df.loc[df['SMOKE'] == 'yes', 'SMOKE'] = 1
df.loc[df['SMOKE'] == 'no', 'SMOKE'] = 0
df.loc[df['SCC'] == 'yes', 'SCC'] = 1
df.loc[df['SCC'] == 'no', 'SCC'] = 0
df.loc[df['CALC'] == 'no', 'CALC'] = 0
df.loc[df['CALC'] == 'Sometimes', 'CALC'] = 1
df.loc[df['CALC'] == 'Frequently', 'CALC'] = 2
df.loc[df['CALC'] == 'Always', 'CALC'] = 3
labels = np.array(df.loc[:, 'NObeyesdad'])
df.drop('NObeyesdad', axis=1, inplace=True)
dataframes.append(df)
original_labels.append(labels)
num_clusters.append(7)

distance_matrices.append(get_dist_matrix(df, 2))

df = pd.read_csv('https://raw.githubusercontent.com/RdgFerreira/ALG2-TP2-Datasets/main/heart_failure_clinical_records_dataset.csv')
labels = np.array(df.loc[:, 'diabetes'])
df.drop('diabetes', axis=1, inplace=True)
dataframes.append(df)
original_labels.append(labels)
num_clusters.append(2)

distance_matrices.append(get_dist_matrix(df, 2))

radius = np.zeros((10, 30))
silhouette_scores = np.zeros((10, 30))
adjusted_rand_scores = np.zeros((10, 30))
exec_times = np.zeros((10, 30))

scikit_radius = np.zeros(10)
scikit_silhouette_scores = np.zeros(10)
scikit_adjusted_rand_scores = np.zeros(10)
scikit_exec_times = np.zeros(10)

for i in range(len(dataframes)):
  df = dataframes[i]
  true_labels = original_labels[i]
  dist_M = distance_matrices[i]

  for j in range(30):
    # 2-approx algorithm
    start_time = time.time()
    Centers, new_labels, indexes = approx_kmeans(dist_M, num_clusters[i])
    exec_times[i][j] = time.time() - start_time
    radius[i][j] = get_max_radius(Centers, indexes, new_labels, dist_M)
    silhouette_scores[i][j] = silhouette_score(df, new_labels)
    adjusted_rand_scores[i][j] = adjusted_rand_score(true_labels, new_labels)

  # scikit approach
  KM = KMeans(n_clusters = num_clusters[i], max_iter=30)
  start_time = time.time()
  KM.fit_predict(df)
  scikit_exec_times[i] = time.time() - start_time
  scikit_radius[i] = get_max_radius(Centers, indexes, KM.labels_, dist_M)
  scikit_silhouette_scores[i] = silhouette_score(df, KM.labels_)
  scikit_adjusted_rand_scores[i] = adjusted_rand_score(true_labels, KM.labels_)

for i in range(len(dataframes)):
  print(scikit_exec_times[i], np.mean(exec_times[i]))

for i in range(len(dataframes)):
  print(scikit_radius[i], np.mean(radius[i]))

for i in range(len(dataframes)):
  print(scikit_silhouette_scores[i], np.mean(silhouette_scores[i]))

for i in range(len(dataframes)):
  print(scikit_adjusted_rand_scores[i], np.mean(adjusted_rand_scores[i]))