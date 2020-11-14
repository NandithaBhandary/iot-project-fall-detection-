from collections import Counter
import math
import pandas as pd 
df = pd.read_csv("fall_detection_train.csv")

Row_list =[]   
# Iterate over each row 
for index, rows in df.iterrows(): 
    # Create list for the current row 
    my_list =[rows.HR, rows.Systolic,rows.Diastolic,rows.Values] 
      
    # append the list to the final list 
    Row_list.append(my_list) 

def knn(data, query, k, distance_fn, choice_fn):
    neighbor_distances_and_indices = []
    
    # 3. For each example in the data
    for index, example in enumerate(data):
        # 3.1 Calculate the distance between the query example and the current
        # example from the data.
        distance1 = distance_fn(example[0:-3], query[0])
        distance2 = distance_fn(example[1:-2], query[1])
        distance3 = distance_fn(example[2:-1], query[2])
        # 3.2 Add the distance and the index of the example to an ordered collection
        neighbor_distances_and_indices.append((distance1, distance2,distance3, index))
    
    # 4. Sort the ordered collection of distances and indices from
    # smallest to largest (in ascending order) by the distances
    sorted_neighbor_distances_and_indices = sorted(neighbor_distances_and_indices)
    
    # 5. Pick the first K entries from the sorted collection
    k_nearest_distances_and_indices = sorted_neighbor_distances_and_indices[:k]
    
    # 6. Get the labels of the selected K entries
    k_nearest_labels = [data[i][3] for distance1, distance2,distance3, i in k_nearest_distances_and_indices]

    # 7. If regression (choice_fn = mean), return the average of the K labels
    # 8. If classification (choice_fn = mode), return the mode of the K labels
    return k_nearest_distances_and_indices , choice_fn(k_nearest_labels)

def mean(labels):
    return sum(labels) / len(labels)

def mode(labels):
    return Counter(labels).most_common(1)[0][0]

def euclidean_distance(point1, point2):
    sum_squared_distance = 0
    for i in range(len(point1)):
        sum_squared_distance += math.pow(point1[i] - point2[i], 2)
    return math.sqrt(sum_squared_distance)


def pred(hr,systo,dia):
    h_rate = [hr]
    bp_s = [systo]
    bp_d = [dia]
    clf_query = [h_rate , bp_s ,bp_d ]
    clf_k_nearest_neighbors, clf_prediction = knn(
        Row_list, clf_query, k=7, distance_fn=euclidean_distance, choice_fn=mode
    )
    print(clf_prediction)

def main():
    return None

if __name__ == '__main__':
    main()





