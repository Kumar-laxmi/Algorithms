# Traveling Sales Problem
import numpy as np
from scipy.spatial.distance import pdist, squareform
import matplotlib.pyplot as plt
# from .solvers.utils import get_cost
from tspy import TSP
from tspy.solvers import NN_solver
import numpy as np
import time
from geopy.geocoders import Nominatim

def get_cost(tour,tsp):
    ans = 0
    for i in range(len(tour)-1):
        ans += tsp.mat[tour[i],tour[i+1]]
    return ans


class TSP:
    """ Base class for a TSP instance"""

    def __init__(self):
        self.tours = {}
        self.lower_bounds = {}

    def read_mat(self, mat):
        """ Reads a distance matrix
        Parameters
        ----------
        mat : NxN numpy matrix 
              Distance matrix for the TSP instance.
        """
        self.N = len(mat)
        self.mat = mat
        for i in range(len(mat)):
            self.mat[i,i] = np.inf

    def read_data(self, data, dist = 'euclidean'):
        """ Reads a data matrix
        Parameters
        ----------
        data : NxP numpy matrix
               Data matrix containing the N P-dimensional data points

        dist : f: x,y -> float 
               Distance function to use in the TSP instance.
        """
        self.data = data
        mat = squareform(pdist(data,dist))
        self.read_mat(mat)
        
    def plot_data(self):
        """ Plots the data if it has been specified"""
        if hasattr(self,'data'):
            plt.scatter(*self.data.T)
            plt.show()
        else:
            raise Exception('No 2d data of the instance has been loaded')

    def get_approx_solution(self, solver):
        """ Compute an approximate solution of the instance
        Parameters
        ----------
        solver : TSP solver
                 Instance of a TSP solver class in the module solvers. 

        Returns
        ----------
        A permutation of the nodes giving an approximate solution to the
        instance.
        """
        tour = solver.solve(self)
        print('The cost is {}.'.format(get_cost(tour,self)))
        self.tours[solver.__class__.__name__] = tour
        return tour

    def Print_Path(self,which,Citys):
        """ Plots a solution"""
        if isinstance(which, int):
            which = list(self.tours.keys())[which]
        tour = self.tours[which]
        print(tour)

        # plt.scatter(*self.data.T)
        # for i in range(self.N):
        #     plt.plot(*self.data[[tour[i],tour[i+1]]].T,'b')
        # plt.show()

        for i in tour:
            print(Citys[i]+"-->", end="")
        print("\n")

    def get_lower_bound(self, method):
        """ Compute a lower bound of the instance
        Parameters
        ----------
        method : Lower bound method
                 Instance of a lower bound class in the module lower_bounds. 

        Returns
        ----------
        A lower bound of the instance.
        """
        sol = method.bound(self)
        print('The lower bound is {}'.format(sol['primal objective']))
        self.lower_bounds[method.__class__.__name__] = sol['primal objective']
        return sol

    def get_best_solution(self):
        """ Returns the best solution computed so far"""
        if not self.tours:
            raise Exception('No solution has been computed yet')
        scores = {s:get_cost(self.tours[s],self) for s in self.tours}
        best = min(scores,key=scores.get)
        print('The best solution is given by {} with score {}'.format(best,scores[best]))
        return self.tours[best]

    def get_best_lower_bound(self):
        """ Returns the best lower bound computed so far"""
        if not self.tours:
            raise Exception('No lower bound has been computed yet')
        best = max(self.lower_bounds,key=self.lower_bounds.get)
        print('The best lower bound is given by {} with score {}'.format(best,self.lower_bounds[best]))
        return self.lower_bounds[best]
        

geolocator = Nominatim(user_agent="ap1")
No_of_city = int(input("Enter no. of city to enter:"))
Citys = []
Loc = []
for i in range(No_of_city):
    city = input()
    Citys.append(city)


start = time.time()

for i in range(No_of_city):
    location = geolocator.geocode(Citys[i])
    loc = (location.latitude, location.longitude)
    Loc.append(loc)

print(np.array(Loc))
# print(Citys)

a = TSP()
a.read_data(Loc)
sol = NN_solver()
a.get_approx_solution(sol)

a.Print_Path('NN_solver',Citys)

end = time.time()
print("The time of execution of above program is :",(end-start), "s")