//This program measures the average amount of time it takes
//  to perform a basic syscall (reading zero bytes from stdin)
//  and prints that value, in microseconds.  The executable
//  expects two command-line arguments: the number of 0-byte
//  reads to average out for each measurement, and the number
//  of measurements to average out for the final reported time,
//  in that order.

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


//perform_measurement: this function performs a single measurement.
//  It takes as input the number of 0-byte reads it should make
//  for the measurment, and returns a float representing the average
//  time it took for each read, in microseconds.
//  The function works by performing reads_per_measurement 0-byte
//  reads in a loop, and requesting the time on either side of the
//  loop so that it can compute the total elapsed time, which then
//  gives the average time for each read.
float perform_measurement(int reads_per_measurement) {
  int fd = fileno(stdin);
  int buf = 0;
  int* bufp = &buf;
  struct timeval start_time;
  struct timeval end_time;
  gettimeofday(&start_time, NULL);
  int i; //To avoid using the -std=c99 compiler flag
  for (i = 0; i < reads_per_measurement; i++) {
    read(fd, bufp, 0);
  }
  gettimeofday(&end_time, NULL);
  return ((float)(1000000 *(end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec))) / reads_per_measurement;
}

//Main begins by interpreting the command-line arguments.  If they are as expected,
//  it proceeds to repeatedly call perform_measurement to find the average time
//  of a syscall, averaging those times out to hopefully get a closer final
//  average.  It then reports the answer.

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Unexpected number of arguments received.  Expected usage: <executable> reads_per_measurement number_of_measurements");
    return 1;
  }
  int reads_per_measurement = atoi(argv[1]);
  int num_measurements = atoi(argv[2]);
  float total_time = 0;
  int i;
  for (i = 0; i < num_measurements; i++) {
    total_time += perform_measurement(reads_per_measurement);
  }
  float average_time = total_time / num_measurements;
  printf("Average Syscall Time: %f microseconds\n(Calculated using the average of %d measurements, each consisting of %d syscalls)\n", average_time, num_measurements, reads_per_measurement);
  return 0;
}
