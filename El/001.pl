my $max = -2147483647;
while(<>)
{
	@ary = $_ =~ /(-?\d+)/g;
	foreach (@ary)
	{
		$max = $_ if $_ > $max;
	}
}
print $max."\n";
