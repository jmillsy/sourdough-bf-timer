## Sourdough bulk fermentation timer

This is a simple hardware timer that will show the percent rise of dough. 

The concept behind this is found in various sourdough articles, such as this [one](https://thesourdoughjourney.com/the-mystery-of-percentage-rise-in-bulk-fermentation/). 

## Device usage

When making sourdough, the beginning phase is to bulkferment dough, and during the process you are stretching the dough. But the duration of the bulk fermantation is a critical part of good bread, but its a non-obvious recipe to follow. The main factor is temperature of the dough, and how much it has risen. The table below is a rough guide to illustrate the point:

| Dough Temperature | Target Percentage Rise | Approximate Timing |
|---|---|---|
| 80F/27C | 30% | 5.5 hours |
| 75F/24C | 50% | 7 hours |
| 70F/21C | 75% | 12 hours |
| 65F/18C | 100% | 16 hours |

## How this works

One you have your mixture of starter, flour, salt, and water, you take a small amount (say 20g) of this dough, and place it inside of a container. This smaller amount will be the control for the rest of your dough as you stretch and fold, or whatever else you do with the rest of the dough. 

On each 5 minute interval, a sensor will take a reading of the top of the jar to the top of the dough. For example, if you started with a jar that is 100m tall. The diamater of this jar doesnt really matter, but it assumes it is vertical without any gradient. 

On the first calibration reading, two important measurements are taken: The dough temp and the distance from the top of the jar. With this temp reading, we can then select a profile we want to follow. At 70F, we need a 75% rise. The first version of this assumes a constant temperature (plus/minus). 

First Reading - 80mm @ 70F - 0% change
<1 hour passes, multiple readings in between>
Next reading - 60mm @ 72F - 25% change
<1 hour passes, multiple readings in between>
Next reading - 40mm @ 71F - 50% change
<1 hour passes, multiple readings in between>
Next reading - 25mm @ 70F - 68% change
<1 hour passes, multiple readings in between>
Next reading - 20mm @ 70F - 75% change

At this point we are done, and ready for shaping and the rest of the bread making process. 