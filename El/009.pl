$n = <>;
@{$ary[0]} = (1);
$len[0] = 1;
@{$ary[1]} = (1);
$len[1] = 1;
for($i=2; $i<=$n; $i++)
{
	for($j=0; $j<$len[$i-1]; $j++)
	{
		$ary[$i][$j] += $ary[$i-1][$j] + $ary[$i-2][$j];
		if($ary[$i][$j] >= 1000000000)
		{
			$ary[$i][$j+1]++;
			$ary[$i][$j] -= 1000000000;
		}
	}
	if($ary[$i][$j])
	{
		$j++;
	}
	$len[$i] = $j;
}
print $ary[$n][$len[$n]-1];
for($i=$len[$n]-2; $i>=0; $i--)
{
	printf "%09d", $ary[$n][$i];
}
print "\n";
