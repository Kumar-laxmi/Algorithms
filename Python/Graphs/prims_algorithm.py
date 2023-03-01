# Importing Libraries
import time
from geopy.geocoders import Nominatim

# Taking input from user
geolocator = Nominatim(user_agent="ap1")
No_of_city = int(input("Enter no. of city to enter:"))
Citys = []
Loc = []
# Taking input from user
for i in range(No_of_city):
    city = input(f"Enter {i+1} City Name : ")
    Citys.append(city)

# Finding Lattitude and longitude
for i in range(No_of_city):
    location = geolocator.geocode(Citys[i])
    loc = (location.latitude, location.longitude)
    Loc.append(loc)

print("\n")
start = time.time()

# Finding Lattitude and longitude 
from geopy.distance import geodesic
G = []
for i in range(No_of_city):
    lst = []
    for j in range(No_of_city):
        nm1=geodesic(Loc[i], Loc[j]).miles
        lst.append(nm1)
    G.append(lst)


# Printing Table Data
INF = 9999999
V = 5
selected = [0, 0, 0, 0, 0]
no_edge = 0
min_cost = 0
selected[0] = True
# Printing Table Data
print("---------------------------------------------------------")
print("Start\t|\tEnd\t|\tDistance\t\t|")
print("--------------------------------------------------------|")
# Calculating Minimum Cost
while (no_edge < V - 1):
    minimum = INF
    x = 0
    y = 0
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if ((not selected[j]) and G[i][j]):  
                    if minimum > G[i][j]:
                        minimum = G[i][j]
                        x = i
                        y = j
    print(str(Citys[x]) + "\t|\t" + str(Citys[y]) + "\t|\t" + str(G[x][y])+"\t|")
    min_cost += G[x][y]
    selected[y] = True
    no_edge += 1

# Printing Minimum Cost
print("---------------------------------------------------------")
print("Minimum Cost:",min_cost)
# Calculating Time of Execution
end = time.time()
print("The time of execution of above program is :",(end-start), "s")
# End of Code