@ary = ($in = <>) =~ /./g;
$i = 0;
foreach (@ary)
{
	if($_ eq "(")
	{
		$i++;
	}
	else
	{
		$i--;
		last if $i < 0;
	}
}
print $i==0?"YES":"NO", "\n";
