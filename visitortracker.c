#include <stdio.h>

#define MAX_VISITORS 100

typedef struct {
    int ages[MAX_VISITORS];
    int count;
    int totalAge;
} VisitorTracker;

void addVisitor(VisitorTracker *tracker, int age) {
    if (tracker->count >= MAX_VISITORS) {
        printf("Visitor limit reached.\n");
        return;
    }

    if (age < 0 || age > 120) {
        printf("Invalid age: %d\n", age);
        return;
    }

    tracker->ages[tracker->count] = age;
    tracker->count++;
    tracker->totalAge += age;
}

void displayStatistics(const VisitorTracker *tracker) {
    if (tracker->count == 0) {
        printf("No visitors recorded.\n");
        return;
    }
  
    int min = tracker->ages[0];
    int max = tracker->ages[0];

    for (int i = 1; i < tracker->count; i++) {
        if (tracker->ages[i] < min) {
            min = tracker->ages[i];
        }

        if (tracker->ages[i] > max) {
            max = tracker->ages[i];
        }
    }

    double average = (double)tracker->totalAge / tracker->count;

    printf("\nVisitor Statistics\n");
    printf("------------------\n");
    printf("Visitor count: %d\n", tracker->count);
    printf("Total age: %d\n", tracker->totalAge);
    printf("Average age: %.2f\n", average);
    printf("Minimum age: %d\n", min);
    printf("Maximum age: %d\n", max);
}

int main(void) {
    VisitorTracker tracker = {{0}, 0, 0};

    int sampleAges[] = {18, 25, 32, 40, 21};
    int n = sizeof(sampleAges) / sizeof(sampleAges[0]);

    for (int i = 0; i < n; i++) {
        addVisitor(&tracker, sampleAges[i]);
    }

    printf("Visitor ages: ");

    for (int i = 0; i < tracker.count; i++) {
        printf("%d ", tracker.ages[i]);
    }

    printf("\n");

    displayStatistics(&tracker);

    return 0;
}

