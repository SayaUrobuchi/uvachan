$n = <>;
$res = $n+1;
for($i=0; ($ii=$i*$i)*3<=$n; $i++)
{
	for($j=$i; ($jj=$j*$j)*2+$ii<=$n; $j++)
	{
		for($k=$j; ($kk=$k*$k)+$ii+$jj<=$n; $k++)
		{
			$res-- if !$hash{$ii+$jj+$kk};
			$hash{$ii+$jj+$kk} = 1;
		}
	}
}
print $res, "\n";
