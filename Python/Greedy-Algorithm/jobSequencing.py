"""
Job Sequencing Algorithm (Greedy Algorithm)
    The greedy approach for job sequencing is a method for scheduling a set of jobs 
    in a way that maximizes the total profit or minimizes the total completion time. 
    The key idea behind this approach is to make locally optimal choices at each step 
    with the hope of finding a globally optimal solution.
    
Input:
  jobs: list of jobs, where each job is a tuple (id, deadline, profit)
  schedule: a fixed schedule, represented as a list of time slots
"""

jobs = []
number_of_jobs = int(input("Enter the number of jobs: "))
schedule = []

for i in range(number_of_jobs):
    default_schedule = int(0)
    job_id = int(input("Enter job id: "))
    job_deadline = int(input("Enter job deadline: "))
    job_profit = int(input("Enter job profit: "))
    jobs.append((job_id, job_deadline, job_profit))
    schedule.append(default_schedule)

def job_sequencing(jobs, schedule):
    """Here we are sorting the jobs in the decreasing order of their profit"""
    jobs.sort(key=lambda x: x[2], reverse=True)
    
    """ Here we are initializing the empty schedule array with job schedule"""
    job_schedule = [0] * len(schedule)
    
    """ Iteration for each job"""
    for job in jobs:
        id, deadline, profit = job
        
        """Iteration for schedule array in the reverse order"""
        for i in range(deadline-1, -1, -1):
            if job_schedule[i] == 0:
                job_schedule[i] = id
                break
    
    """ We will now calculate the total maximum profit that can be obtained"""
    total_profit = sum([job[2] for i, job in enumerate(jobs) if job[0] in job_schedule])
    
    return job_schedule, total_profit

job_schedule, total_profit = job_sequencing(jobs, schedule)
print("Job Schedule:", job_schedule)
print("Total Profit:", total_profit)
