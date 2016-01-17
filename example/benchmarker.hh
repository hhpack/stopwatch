<?hh //partial

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\performance\BenchMarker;
use hhpack\performance\TimeWatcher;
use hhpack\performance\MemoryWatcher;
use hhpack\performance\reporter\TextReporter;

async function benchmarker_main() : Awaitable<void>
{
    $bechmarker = new BenchMarker(new TextReporter());
    $bechmarker->start();

    await \HH\Asio\usleep(2000);

    $bechmarker->stop();
}

\HH\Asio\join(benchmarker_main());
