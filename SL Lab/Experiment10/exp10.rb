marks={
    'science'=> 50,
    'maths'=> 60,
    'social'=>55
}
total = 0
marks.each {|key,value|
              total +=value
        } 
puts "Total Marks: "+ total.to_s
