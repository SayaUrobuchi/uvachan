$n = <>;
$head = $n;
$next[$n] = $n+1;
for($i=0; $i<$n; $i++)
{
	$in = <>;
	$ary[$i][$n+1] = 1;
	for($j=0; $j<$i; $j++)
	{
		if(substr($in, $j, 1) eq "+")
		{
			$ary[$i][$j] = 1;
		}
		else
		{
			$ary[$j][$i] = 1;
		}
	}
	for($j=$next[$head], $now=$head; ; $now=$j, $j=$next[$j])
	{
		if($ary[$i][$j])
		{
			$next[$i] = $j;
			$next[$now] = $i;
			last;
		}
	}
}
for($i=$next[$head]; $i!=$n+1; $i=$next[$i])
{
	print $ch, $i+1;
	$ch = ' ';
}
print "\n";
