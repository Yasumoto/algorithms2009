#!/usr/bin/env python

# Joe Smith
# Chapman University
# CPSC 440 - Algorithm Analysis
# Erik Linstead
# Released under GPLv2+

# kmeans.py
# given a dataset, calculate the clusters.  
import math


list = []

list.append([3.8520683,4.1883604])
list.append([3.8090105,4.1844398])
list.append([3.8658962,4.1883151])
list.append([3.8155536,4.2114524])
list.append([3.8231807,4.2042954])
list.append([3.8365686,4.2023431])
list.append([3.7660288,4.2476751])
list.append([3.8460341,4.1947237])
list.append([3.8678652,4.2076287])
list.append([3.7275603,4.1765820])
list.append([3.7833109,4.2520583])
list.append([3.8585020,4.2328568])
list.append([3.8801014,4.2193686])
list.append([3.7547298,4.2017050])
list.append([3.7499434,4.2536358])
list.append([3.7761396,4.2473985])
list.append([3.8319298,4.2388829])
list.append([3.7605048,4.1923295])
list.append([3.7834023,4.2198319])
list.append([3.8779867,4.2084238])
list.append([3.8144566,4.2665211])
list.append([3.8438305,4.1891052])
list.append([3.7895529,4.1939936])
list.append([3.7898395,4.2001147])
list.append([3.7875347,4.2621905])
list.append([3.8188705,4.2498828])
list.append([3.7654732,4.2162966])
list.append([3.8400892,4.2447599])
list.append([3.7931167,4.2265524])
list.append([3.7407667,4.2288681])
list.append([3.8011791,4.2283497])
list.append([3.8356293,4.2248579])
list.append([3.7844509,4.2704223])
list.append([3.7711322,4.2312746])
list.append([3.7927428,4.1976655])
list.append([3.8195483,4.2251721])
list.append([3.7810047,4.2489682])
list.append([3.8010418,4.2650299])
list.append([3.8237195,4.1904232])
list.append([3.7094634,4.2119128])
list.append([3.8307508,4.2079698])
list.append([3.7461322,4.2777955])
list.append([3.8065085,4.2400753])
list.append([3.7978164,4.2232236])
list.append([3.7802103,4.2171011])
list.append([3.8164625,4.2647290])
list.append([3.8172137,4.2123649])
list.append([3.7932565,4.2001982])
list.append([3.7332539,4.2157221])
list.append([3.7672827,4.2566482])
list.append([3.8255439,4.2105991])
list.append([3.8409819,4.2100444])
list.append([3.7985567,4.1939366])
list.append([3.8355473,4.2324590])
list.append([3.8145987,4.2059518])
list.append([3.8116802,4.1940447])
list.append([3.8540858,4.2188345])
list.append([3.7897071,4.2197296])
list.append([3.8596372,4.2050571])
list.append([3.7835421,4.2644426])
list.append([3.7998957,4.2567978])
list.append([3.8860394,4.2182941])
list.append([3.8651255,4.2020155])
list.append([3.8215229,4.2592017])
list.append([3.8068703,4.2065992])
list.append([3.8245053,4.2599056])
list.append([3.7927842,4.2078853])
list.append([3.8311272,4.2632353])
list.append([3.8234773,4.2275545])
list.append([3.7774500,4.2220819])
list.append([3.8406408,4.2582344])
list.append([3.8076465,4.2095701])
list.append([3.7401032,4.2448428])
list.append([3.8765688,4.2036555])
list.append([3.8474439,4.2263606])
list.append([3.7838446,4.2576279])
list.append([3.8338831,4.2320691])
list.append([3.7629111,4.2412997])
list.append([3.7922181,4.1876904])
list.append([3.7988122,4.1947650])
list.append([3.7936372,4.2417299])
list.append([3.8406236,4.2163060])
list.append([3.8371583,4.2136002])
list.append([3.7426830,4.1928118])
list.append([3.8210196,4.2295690])
list.append([3.8586736,4.1862526])
list.append([3.7856546,4.2279850])
list.append([3.8944446,4.2320919])
list.append([3.7786038,4.2903073])
list.append([3.8200811,4.2365121])
list.append([3.8247094,4.2094079])
list.append([3.8007735,4.2474807])
list.append([3.7095380,4.2071397])
list.append([3.7218797,4.2068828])
list.append([3.8180798,4.2278537])
list.append([3.8243809,4.2406852])
list.append([3.7844664,4.2200296])
list.append([3.7926689,4.1976085])
list.append([3.7075603,4.0253451])
list.append([3.6791919,4.1343476])
list.append([3.6161032,4.1045978])
list.append([3.6420925,4.0773645])
list.append([3.6622772,4.1112082])
list.append([3.5474166,4.0629598])
list.append([3.6583578,4.1084758])
list.append([3.5403946,4.1172956])
list.append([3.6502180,4.0359340])
list.append([3.7436651,4.1385380])
list.append([3.6634906,4.1222087])
list.append([3.5826892,4.0855138])
list.append([3.5443295,3.8393756])
list.append([3.6831690,4.1604436])
list.append([3.5776676,4.0298033])
list.append([3.7730802,3.9341815])
list.append([3.5852872,4.0872332])
list.append([3.4639835,3.8892180])
list.append([3.6068573,4.1158911])
list.append([3.6455191,4.0180500])
list.append([3.4449535,3.8483308])
list.append([3.5954909,4.0098811])
list.append([3.6237889,4.0656919])
list.append([3.5574957,3.9925845])
list.append([3.6781172,4.1411026])
list.append([3.6433888,4.1099035])
list.append([3.5201049,4.0513713])
list.append([3.5989584,4.0823875])
list.append([3.5278130,4.0061739])
list.append([3.6326269,4.1094383])
list.append([3.6169183,4.1267096])
list.append([3.4918397,3.9693231])
list.append([3.6298431,4.0183057])
list.append([3.5760025,4.0478137])
list.append([3.7297622,4.1141704])
list.append([3.6427362,4.0094805])
list.append([3.5131056,3.9808795])
list.append([3.6474925,4.0070402])
list.append([3.4062869,3.9384287])
list.append([3.7121518,4.0759099])
list.append([3.6634485,4.1611614])
list.append([3.5929000,4.0790137])
list.append([3.3837298,3.9284434])
list.append([3.7067507,4.1776749])
list.append([3.6285922,4.0694956])
list.append([3.6391504,4.1593195])
list.append([3.6151631,4.1375562])
list.append([3.6115338,4.0270700])
list.append([3.5807738,3.9636202])
list.append([3.6838123,4.0773972])
list.append([3.5506431,3.9642353])
list.append([3.5175747,3.8983416])
list.append([3.6937470,4.1403958])
list.append([3.6737274,4.1971676])
list.append([3.6728435,4.0655404])
list.append([3.6074252,4.0748695])
list.append([3.6411967,4.1305810])
list.append([3.6142455,4.0454173])
list.append([3.5503466,3.9941958])
list.append([3.7795264,4.1558839])
list.append([3.5391284,4.0188104])
list.append([3.4777014,4.0092466])
list.append([3.6645225,4.1501692])
list.append([3.4668823,3.9704460])
list.append([3.6259006,4.0685660])
list.append([3.6653516,4.1206276])
list.append([3.6904660,4.0935847])
list.append([3.6427369,4.1224793])
list.append([3.5984302,4.0351987])
list.append([3.4786897,3.8683006])
list.append([3.6032210,4.1773361])
list.append([3.6730345,4.1508853])
list.append([3.5945644,4.1403427])
list.append([3.4611984,4.0121241])
list.append([3.3680273,3.8313047])
list.append([3.4669831,4.0218152])
list.append([3.6617596,4.1275953])
list.append([3.5599168,4.0628995])
list.append([3.4583153,3.8513053])
list.append([3.6933750,4.1320181])
list.append([3.6805559,4.0006146])
list.append([3.6548721,4.0792459])
list.append([3.5113424,4.1382645])
list.append([3.6683990,4.0936502])

#Here we go!


# Choose two random points to start with
import random
randomly_chosen_one = random.randint(0,len(list))
randomly_chosen_two = random.randint(0,len(list))

first = list[randomly_chosen_one]
second = list[randomly_chosen_two]

print first
print second

# Set up the values that will eventually check to see if we've reached stability
orig_first = [5.0, 5.0]
orig_second = [5.0, 5.0]

# For graphing
from pylab import *


while (orig_first != first and orig_second != second):

	orig_first[0] = first[0]
	orig_first[1] = first[1]

	orig_second[0] = second[0]
	orig_second[1] = second[1]

# the list of which points are located in which cluster
	belonging = []

	#Euclidean distance (2 dimensions)
	def distance(a, b):
	    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

	first_sums = [0, 0]
	first_count = 0
	second_sums = [0, 0]
	second_count = 0

	for i in list:
# does this point belong to the first cluster?
# check which 'mean' (kind of the center) it is closer to
	    if distance(first, i) < distance(second, i):
		belonging.append(0)
# include it's x and y distance in the sum for the first cluster
		first_sums[0] += i[0]
		first_sums[1] += i[1]
		first_count += 1
	    else:
#otherwise, it goes to the other one
		belonging.append(1)
		second_sums[0] += i[0]
		second_sums[1] += i[1]
		second_count += 1


	first[0] = first_sums[0] / first_count
	first[1] = first_sums[1] / first_count

	second[0] = second_sums[0] / second_count
	second[1] = second_sums[1] / second_count


print "The actual stuff is:"

num = 0


# Plot jargon
for i in list:
	if (belonging[num] == 0):
#scatter plots do point plotting (must be given a list as an argument)
		scatter([i[0]], [i[1]], c='b')
		scatter([i[0]], [i[1]], c='b')
	else:
		scatter([i[0]], [i[1]], c='y')
		scatter([i[0]], [i[1]], c='y')
	num += 1
	
	
# display both of the means in a distinctive color.
scatter([first[0]], [first[1]], c='g')
scatter([second[0]], [second[1]], c='r')
show()
