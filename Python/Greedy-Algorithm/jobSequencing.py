# Job Sequencing Problem (Greedy Algorithm)

jobs = []
num_of_jobs = int(input("Enter the number of jobs: "))

for i in range(num_of_jobs):
    job_id = int(input("Enter job id: "))
    job_deadline = int(input("Enter job deadline: "))
    job_profit = int(input("Enter job profit: "))
    jobs.append((job_id, job_deadline, job_profit))

# Sort jobs in descending order of profit
jobs = sorted(jobs, key=lambda x: x[2], reverse=True)

# Initialize an array to keep track of the deadline of each job
job_slots = [False] * num_of_jobs

# Initialize a variable to keep track of the total profit
total_profit = 0

# Iterate through each job
for job in jobs:
    for i in range(min(job[1]-1, num_of_jobs-1), -1, -1):
        if not job_slots[i]:
            job_slots[i] = True
            total_profit += job[2]
            break

print("Optimal Sequence of Jobs:")
for i in range(num_of_jobs):
    if job_slots[i]:
        print(jobs[i][0])

print("Maximum Profit: ", total_profit)
