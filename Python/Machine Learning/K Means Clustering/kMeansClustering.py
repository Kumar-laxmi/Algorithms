# 👉 K-Means Clustering is an unsupervised learning algorithm that is used to solve the clustering problems in machine learning or data science.

# 👉 It groups the unlabeled dataset into different clusters.

# STEPS
# =====
# ⇒ Initialize first k clusters.
# ⇒ Find distance of each data point from these k clusters, using Manhattan Distance Formula
# ⇒ Assign each point to the respective cluster based on their shortest distance from the cluster points.

initCluster = []  # list of initial cluster points' names
pointDist = []  # list of distance between points
coordName = []  # list of coordinates' names
clusterPt1, clusterPt2, clusterPt3 = [], [], []  # initial cluster points
cluster1 = []  # list for names of classified cluster 1 points
cluster2 = []  # list for names of classified cluster 2 points
cluster3 = []  # list for names of classified cluster 3 points
clusterPtDist = {}  # map for distances b/w clusters & points
k = 3  # k - value


# class with attributes coordinate name and x, y coordinates for each data point
class Coordinate:
    def __init__(self, coordName, x, y):
        self.coordName = coordName  # coordinate name
        self.x = x  # x - coordinate
        self.y = y  # y - coordinate


coordinateObjList = []  # list of objects of coordinate class


# calculate Manhattan Distance between a data point and cluster point
def getDistance(coordinateObjList, clusterPt, x):
    dist = abs(coordinateObjList[x].x - clusterPt[0]) + abs(coordinateObjList[x].y - clusterPt[1])

    clusterPtDist[dist] = clusterPt  # insert distance along with cluster

    return dist


# function for implementing clustering algorithm
def clusteringAlgo(coordinateObjList, n):
    # set initial cluster points
    j = 0
    for i in range(n):
        if coordinateObjList[i].coordName == initCluster[j]:
            j += 1
            if not clusterPt1:
                clusterPt1.append(coordinateObjList[i].x)
                clusterPt1.append(coordinateObjList[i].y)
            else:
                clusterPt1[0] = coordinateObjList[i].x
                clusterPt1[1] = coordinateObjList[i].y

    # iterates through all data points except for last k points
    for i in range(n - k):
        # checks if current coordinate name not present in initial cluster names
        if coordinateObjList[i].coordName not in initCluster:
            # find distance of ith point from the k clusters
            for j in range(k):
                pointDist.append(getDistance(coordinateObjList, clusterPt1, i))
                pointDist.append(getDistance(coordinateObjList, clusterPt1, i))
                pointDist.append(getDistance(coordinateObjList, clusterPt1, i))

            # find closest cluster from ith point
            minDist = min(pointDist)

            # iterate through the elements of the clusterPtDist dictionary (map)
            for dist, point in clusterPtDist.items():
                # checks if the minimum distance (minDist) matches the distance from the map (map key)
                if minDist == dist:
                    # If there is a match, it identifies the cluster point (point) corresponding to the minimum distance (minDist)

                    # first cluster closest to current data point
                    if point[0] == clusterPt1[0] and point[1] == clusterPt1[1]:
                        # update cluster1 list with current data point's name
                        cluster1.append(coordinateObjList[i].coordName)
                        # update cluster point with new point (calculate average)
                        clusterPt1[0] = (
                            clusterPt1[0] + coordinateObjList[i].x) / 2  # x - coordinate updation
                        clusterPt1[1] = (
                            clusterPt1[1] + coordinateObjList[i].y) / 2  # y - coordinate updation

                    # second cluster closest to current data point
                    elif point[0] == clusterPt2[0] and point[1] == clusterPt2[1]:
                        # update cluster2 list with current data point's name
                        cluster1.append(coordinateObjList[i].coordName)
                        # update cluster point with new point (calculate average)
                        clusterPt2[0] = (
                            clusterPt2[0] + coordinateObjList[i].x) / 2
                        clusterPt2[1] = (
                            clusterPt2[1] + coordinateObjList[i].y) / 2

                    # third cluster closest to current data point
                    elif point[0] == clusterPt3[0] and point[1] == clusterPt3[1]:
                        # update cluster3 list with current data point's name
                        cluster1.append(coordinateObjList[i].coordName)
                        # update cluster point with new point (calculate average)
                        clusterPt3[0] = (
                            clusterPt3[0] + coordinateObjList[i].x) / 2
                        clusterPt3[1] = (
                            clusterPt3[1] + coordinateObjList[i].y) / 2

                coordName.clear()  # clear coordinate name's vector for next iteration
        pointDist.clear()  # clear point distance vector for next iteration


# function to show clusters with classified points
def showClusters():
    print("Classified Data Points :\nCluster 1 :", end=" ")
    for c in cluster1:
        print(c, end=" ")

    print("\nCluster 2 :", end=" ")
    for c in cluster2:
        print(c, end=" ")

    print("\nCluster 3 :", end=" ")
    for c in cluster3:
        print(c, end=" ")


# main function definition
def main():
    print("\n\t=== K MEANS CLUSTER ===")

    # input no. of data points
    n = int(input("Enter no. of data points : "))

    print("Enter data points (coordName x y) :", end=" ")
    for i in range(n):
        inpString = input()  # input coordinate name and coordinates
        values = inpString.split()  # split input values
        # create an object with respective values
        coordinateObjList.append(Coordinate(values[0], int(values[1]), int(values[2])))

    # choose initial cluster points
    print("Choose 3 clusters point among the following :")
    for i in range(n):
        print("{0}. ({1}, {2})".format(
            coordinateObjList[i].coordName, coordinateObjList[i].x, coordinateObjList[i].y))

    inpString = input("\nMAKE YOUR CHOICES : ")
    values = inpString.split()
    for i in range(k):
        initCluster.append(values[i])

    # function call to classify the data points in clusters
    clusteringAlgo(coordinateObjList, n)

    # function call to display clusters with classified data points
    showClusters()


main()
