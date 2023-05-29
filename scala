spark-shell

val text = sc.textfile("");
text.collect;
val counts = text.flatMap(line => line.split(""));
counts.collect;
val mapf = counts.map(word => (word,1));
val reduce = mapf.reduceByKey(_+_);
reduce.collect


spark-shell

val text = sc.textfile()
val x = text.flatMap(line => line.split("")
val t = x.map(c => (c,1))
val f = t.reduceByKey(_+_)
f.collect
