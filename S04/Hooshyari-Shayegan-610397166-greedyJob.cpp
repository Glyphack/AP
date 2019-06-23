#include <iostream>

using std::cin;
using std::cout;
using std::qsort;
using std::endl;

class Job {
public:
    int id, start_time, finish_time;

    Job(int job_id, int job_start_time, int job_finish_time) {
        id = job_id;
        start_time = job_start_time;
        finish_time = job_finish_time;
    }

    Job() {
        id = 0;
        start_time = 0;
        finish_time = 0;
    }
};


void SortJobs(Job *jobs, int jobs_count) {
    Job temp_job;
    for (int i = 0; i < jobs_count; i++) {
        for (int j = 0; j < i; j++) {
            if (jobs[i].finish_time < jobs[j].finish_time) {
                temp_job = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp_job;
            }
        }
    }
}


int MaximumJobsDone(Job *jobs, int jobs_count) {
    SortJobs(jobs, jobs_count);
    int jobs_done = 0;
    Job current_job = jobs[0];
    jobs_done++;
//    cout<<"doing "<<current_job.id<<endl;
    for (int i = 1; i < jobs_count; i++) {
        if (jobs[i].start_time >= current_job.finish_time) {
            jobs_done++;
//            cout<<"doing "<<jobs[i].id<<endl;
            current_job = jobs[i];
        }
    }
    return jobs_done;
}


int main() {
    int jobs_count, job_id, job_start_time, job_finish_time;
    cin >> jobs_count;
    Job jobs[jobs_count];
    for (int i = 0; i < jobs_count; i++) {
        cin >> job_start_time >> job_finish_time;
        jobs[i] = Job(i, job_start_time, job_finish_time);
    }
    cout << MaximumJobsDone(jobs, jobs_count);

}
