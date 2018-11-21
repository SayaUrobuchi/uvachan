($n, $m, $d) = ($in = <>) =~ /\d+/g;
for($i=0; $i<$n*$m*$d; )
{
	$in = <>;
	@temp = $in =~ /(-?\d+)/g;
	foreach (@temp)
	{
		$ary[$i/$n/$m+1][$i/$m%$n+1][$i%$m+1] = $_;
		$i++;
	}
}
for($k=1; $k<=$d; $k++)
{
	for($i=1; $i<=$n; $i++)
	{
#		$in = <>;
#		if($in !~ /\d+/)
#		{
#			$i--;
#			$cnt++;
#			if($cnt > 50)
#			{
#				exit;
#			}
#			next;
#		}
#		@{$ary[$k][$i]}[1..$m] = $in =~ /(-?\d+)/g;
		for($j=1; $j<=$m; $j++)
		{
			$dp[$k][$i][$j] = $ary[$k][$i][$j] + $dp[$k][$i][$j-1] + 
				$dp[$k][$i-1][$j] - $dp[$k][$i-1][$j-1];
		}
	}
}
$max = -2147483647;
for($i=1; $i<=$n; $i++)
{
	for($j=$i; $j<=$n; $j++)
	{
		for($p=1; $p<=$m; $p++)
		{
			for($q=$p; $q<=$m; $q++)
			{
				for($k=1, $sum=0; $k<=$d; $k++)
				{
					$sum += $dp[$k][$j][$q] - $dp[$k][$i-1][$q] - 
						$dp[$k][$j][$p-1] + $dp[$k][$i-1][$p-1];
					$max = $sum if $sum > $max;
					$sum = 0 if $sum < 0;
				}
			}
		}
	}
}
print $max, "\n";
