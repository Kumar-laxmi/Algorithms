

def schedule_jobs(jobs):
    n = len(jobs)
    # Sort jobs in descending order of profit per unit time
    jobs.sort(key=lambda x: x[2]/x[1], reverse=True)
    schedule = [0] * n
    total_profit = 0
    for i in range(n):
        for j in range(min(n, jobs[i][1]) - 1, -1, -1):
            if schedule[j] == 0:
                schedule[j] = i + 1
                total_profit += jobs[i][2]
                break
    return schedule, total_profit

# Sample usage
job_count = int(input("Enter the number of jobs: "))
jobs = []``
for i in range(job_count):
    job_name = input("Enter the name of job {}: ".format(i+1))
    deadline = int(input("Enter the deadline of job {}: ".format(i+1)))
    profit = int(input("Enter the profit of job {}: ".format(i+1)))
    jobs.append([job_name, deadline, profit])
schedule, profit = schedule_jobs(jobs)
print("Optimal Schedule: ", schedule)
print("Maximum Profit: ", profit)
