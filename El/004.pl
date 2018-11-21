$n = <>;
for($i=0; $i<$n; $i++)
{
	($mass[$i], $str[$i]) = ($in = <>) =~ /(\d+)\s+(\d+)/;
	$idx[$i] = $i;
}
@ary = sort {$mass[$a] <=> $mass[$b] or $str[$a] <=> $str[$b]} @idx;
$sum = 0;
$max = 0;
for($i=0; $i<$n; $i++)
{
	if($str[$ary[$i]] >= $sum)
	{
		$sum += $mass[$ary[$i]];
		$max++;
	}
}
print $max."\n";
